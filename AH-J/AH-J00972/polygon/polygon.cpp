#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    int sum = 0;
    for(int i = 0;i < n-2;i++)
    {
        for(int j = i+2;j < n;j++)
        {
            int cnt = 0;
            int maxn = INT_MIN;
            for(int k = i;k <= j;k++)
            {
                cnt += a[k];
                maxn = max(maxn,a[k]);
            }
            if(cnt > 2 * maxn)sum++;

        }
    }
    cout << sum % 998244353;
    return 0;
}
//I AK CSP-J 2025!

//草稿
/*
for(int i = 1;i <)



*/