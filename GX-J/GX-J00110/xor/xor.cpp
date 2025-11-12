#include <bits/stdc++.h>
using namespace std;

void dfs(int, int);

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    vector<int> p;
    int n, k;
    cin >> n >> k;
    int num1 = 0, num0 = 0;
    for (int i = 1; i <= n ;i++)
    {
        int pp;
        cin >> pp;
        p.push_back(pp);
        if (pp == 1) num1++;
        if (pp == 0) num0++;
    }
    if (k == 0 && num1 == p.size())
    {
        cout << n / 3 <<'\n';
        return 0;
    }


    return 0;
}

