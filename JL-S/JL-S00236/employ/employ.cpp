#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[1010];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    for (int i=0;i<n;i++)   cin>>a[i];
    sort(a,a+n);
    if (m==1)
    {
        long long cnt=0,ans=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='1')  cnt++;
            else
            {
                int t=n;
                for (int j=0;j<n;j++)
                    if (a[j]>cnt)
                    {
                        t=j;
                        break;
                    }
                if (t==n)   t=1;
                else t=max(1,n-t);
                long long tmp=1;
                for (int j=1;j<=n-1;j++)
                    tmp=tmp*j%Mod;
                tmp%=Mod;
                tmp*=t;
                ans+=tmp;
                ans%=Mod;
            }
        }
        cout<<ans%Mod;
    }
    else cout<<0;
    return 0;
}
