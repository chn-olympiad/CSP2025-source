#include <iostream>
#include <ios>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

struct s
{
    unsigned long long l;
    unsigned long long r;
};

bool myless(s s0, s s1)
{
    if (s0.l == s1.l)
    {
        return s0.r < s1.r;
    }
    else return s0.l < s1.l;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::vector;
    using std::pair;
    using std::max;
    using std::sort;
    cin.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    unsigned int n;
    unsigned long long k;
    cin >> n >> k;
    vector<unsigned long long> nums(n);
    vector<vector<unsigned long long>> b(n, vector<unsigned long long>(n, 0xffffffffffffffff));
    vector<s> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    // yup, it's brute-force time again
    // calculate all xor values
    for (int i = 0; i < n; ++i)
    {
        unsigned long long ac = nums[i];
        b[i][i] = ac;
        if (b[i][i] == k)
        {
            c.push_back({i, i});
        }
        for (int j = i + 1; j < n; ++j)
        {
            b[i][j] = ac ^ nums[j];
            if (b[i][j] == k)
            {
                s il;
                il.l = i;
                il.r = j;
                c.push_back(il);
            }
        }
    }
    sort(c.begin(), c.end(), myless);
    // find all combinations and get the biggest
    unsigned long long ans = 0;/*
    for (int i = 0; i < n; ++i)
    {
        std::cerr << c[i].l << ' ' << c[i].r << '\n';
    }*/
    for (int i = 0; i < c.size(); ++i)
    {
        unsigned long long curans = 1;
        unsigned long long curr = c[i].r;
        for (int j = i + 1; j < c.size(); ++j)
        {
            if (c[j].l > curr)
            {
                ++curans;
                curr = c[j].r;
            }
        }
        ans = max(ans, curans);
    }
    cout << ans << '\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}
