#include<bits/stdc++.h>
using namespace std;
int n,a[5009],sum[5009],l[5009],ans;
stack<int>st;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=7;i<min(1<<20,1<<n);++i)
    {
        int cnt=0,sum=0,mx=0;
        for(int j=0;j<=min(20,n);++j)
        {
            if(i&(1<<j))
            {
                ++cnt;
                mx=max(mx,a[j+1]);
                sum+=a[j+1];
            }
        }
        if(cnt>2&&sum>mx*2)++ans;
    }
    cout<<ans;
    return 0;
}