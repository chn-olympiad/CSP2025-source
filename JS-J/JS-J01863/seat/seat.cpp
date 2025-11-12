#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <utility>

bool mygreater(short a, short b) {return a > b;}

int findScore(const std::vector<short> &scores, short target)
{
    int l = 0, r = scores.size() - 1;
    if (scores[l] == target) return l;
    if (scores[r] == target) return r;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (scores[m] == target) return m;
        if (scores[m] > target) l = m;
        if (scores[m] <= target) r = m;
    }
    return r;
}

std::pair<int, int> getCR(int n, int m, int idx)
{
    int c = idx / m;
    int mod = c % 2;
    int r = mod == 0 ? idx % n : n - idx % n - 1;
    return {c, r};
}

int main()
{
    using std::cin;
    using std::cout;
    using std::vector;
    using std::sort;
    using std::find;
    cin.tie(nullptr);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<short> a(n * m, 0);
    for (int i = 0; i < n * m; ++i)
    {
        cin >> a[i];
    }
    short score = a[0];
    sort(a.begin(), a.end(), mygreater);
    int idx = findScore(a, score);
    auto cr = getCR(n, m, idx);
    int c = cr.first;
    int r = cr.second;
    cout << c + 1 << ' ' << r + 1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
