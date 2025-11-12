#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int a[N], s[N];
int n, k;
vector<pair<int, int>> sgs, tmp;

int fun(int l, int r)
{
    return s[r] ^ s[l - 1];
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] ^ a[i];
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            if (fun(i, j) == k)
                sgs.push_back({i, j});

    int r = 0x3f3f3f3f;
    for (auto sg : sgs)
    {
        int l = sg.first;
        if (tmp.size() == 0)
            tmp.push_back(sg), r = sg.second;
        else if (l > r)
            tmp.push_back(sg), r = sg.second;
        else
            r = min(r, sg.second);
    }

    cout << tmp.size() << endl;

    return 0;
}
