#include <bits/stdc++.h>
using namespace std;
int a[5005];
const int mod = 998244353;
bool check(int x,int y)
{
    int maxn=0,cnt=0;
    for(int i=x;i<=y;i++)
    {
        maxn=max(maxn,a[i]);
        cnt+=a[i];
    }
    if(cnt>maxn*2)
        return 1;
    return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int maxn=0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        maxn=max(maxn,a[i]);
    }
    int sum=0;
    if(n==3)
    {
        int maxn=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>2*maxn) cout << 1;
        else cout << 0;
        return 0;
    }
    if(maxn==1)
    {
        cout << n-3+1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<i)
                continue;
            if(j-i<3)
                continue;
            if(check(i,j))
                sum++;
            sum%=mod;
        }
    }
    cout << sum;
    return 0;
}
