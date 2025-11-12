#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 1e6 + 9;

char s[N];

std::vector<int> vec;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    scanf("%s", s);
    for (auto c : s)
        if (c >= '0' && c <= '9')
            vec.emplace_back(-(c - '0'));

    std::sort(vec.begin(), vec.end());

    for (auto it : vec)
        printf("%d", -it);

    fclose(stdin);
    fclose(stdout);

    return 0;
}