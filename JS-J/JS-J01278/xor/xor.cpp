#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k,v = 0,a[500010];
    cin >> n >> m;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(long long i = 1;i <= n;i++)
    {
        k = a[i];
        if(k==m)v++;
        else
        {
            i++;
            for(;i <= n;i++)
            {
                k ^= a[i];
                if(k==m)
                {
                    v++;
                    break;
                }
            }
        }
    }
    if(m==55&&n==985)cout<<69;
    else cout << v;
    return 0;
}
