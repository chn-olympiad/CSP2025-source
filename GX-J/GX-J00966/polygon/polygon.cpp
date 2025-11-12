#include<iostream>
#include<algorithm>

using namespace std;
int n;
int a[5007];
long long ans;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<(1<<n);i++)
    {
        int cnt=0;
        int t=0;
        for (int j=1;j<=n;j++)
            if (i & (1<<j))
            {
                cnt+=a[j];
                t=max(t,j);
            }
        if (cnt>a[t]*2)
            ans=(ans+1)%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
