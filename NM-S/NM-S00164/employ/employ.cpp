#include<bits/stdc++.h>
using namespace std;
#define int long long

int s[510], c[510], sum_c[510];

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
        //if(c[i] <= i)
       // sum_c[i] = sum_c[i - 1] + c[i];
    }

    int ret = 0;

    return 0;
}
