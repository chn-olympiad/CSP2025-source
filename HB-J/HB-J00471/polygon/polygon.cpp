#include<bits/stdc++.h>
using namespace std;
long long n,a[5002],cnt,ans,max1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=3;j<=n;j++)
        {
            int knt=1;
            for(int k=i;k<=n;k++)
            {
                if(knt==j) break;
                cnt+=a[k];
                knt++;
                max1=max(max1,a[k]);
            }
            if(cnt>max1*2) ans++;
        }

    }
    cout<<ans%998244353;
    return 0;
}
