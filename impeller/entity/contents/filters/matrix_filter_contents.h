// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "impeller/entity/contents/filters/filter_contents.h"
#include "impeller/entity/contents/filters/inputs/filter_input.h"

namespace impeller {

class MatrixFilterContents final : public FilterContents {
 public:
  MatrixFilterContents();

  ~MatrixFilterContents() override;

  void SetMatrix(Matrix matrix);

  // |FilterContents|
  Matrix GetLocalTransform(const Matrix& parent_transform) const override;

 private:
  // |FilterContents|
  std::optional<Snapshot> RenderFilter(
      const FilterInput::Vector& input_textures,
      const ContentContext& renderer,
      const Entity& entity,
      const Matrix& effect_transform,
      const Rect& coverage) const override;

  Matrix matrix_;

  FML_DISALLOW_COPY_AND_ASSIGN(MatrixFilterContents);
};

}  // namespace impeller
