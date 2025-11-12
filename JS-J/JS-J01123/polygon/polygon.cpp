#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5010],d[5010],bucket[5010];
const int MOD=998244353;

int main()
{
    freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];bucket[a[i]]++;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=a[i]+d[i-1];
    for(int i=n;i>=3;i--)
    {
        for(int j=n-1;j>=1;j--)
        {
            for(int k=j-1;k>=1;k--)
            {
                if(d[j]-d[k]>a[i]) ans++;
            }
        }

    }
    cout<<ans%MOD;
    return 0;
}
