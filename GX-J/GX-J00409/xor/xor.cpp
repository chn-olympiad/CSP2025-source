#include <cstdio>
#include <utility>

int numSize, targetNum, answer, prexor[500005];

std::pair<int, int> check_son(int left_limit, int right_limit) {
    int part_answer = 0, max_right_side = right_limit;
    for (int index0 = left_limit + 1; index0 <= right_limit; ++index0) {
        for (int index1 = index0; index1 <= right_limit; ++index1) {
            if ((prexor[index1 + 1] ^ prexor[index0]) == targetNum) {
                auto result = check_son(index0, index1);
                if (result.first >= 1) {
                    part_answer += result.first;
                    index0 = result.second;
                    max_right_side = result.second;
                } else {
                    part_answer++;
                    index0 = index1;
                    max_right_side = index1;
                }
                break;
            }
        }
    }
    return {part_answer, max_right_side};
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d %d", &numSize, &targetNum);
    for (int i = 0; i < numSize; ++i) {
        int tmp;
        scanf("%d", &tmp);
        prexor[i + 1] = prexor[i] ^ tmp;
    }

    for (int index0 = 0; index0 < numSize; ++index0) {
        for (int index1 = index0; index1 < numSize; ++index1) {
            if ((prexor[index1 + 1] ^ prexor[index0]) == targetNum) {
                auto result = check_son(index0, index1);
                if (result.first >= 1) {
                    answer += result.first;
                    index0 = result.second;
                } else {
                    answer++;
                    index0 = index1;
                }
                break;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}

// Is it true?