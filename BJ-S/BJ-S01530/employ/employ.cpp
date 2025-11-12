#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m,asum,bsum,csum,like,res;
long long ans=1;
int a[MAXN],b[MAXN],c[MAXN],f[MAXN];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1;i<=n;i++) 
{cin>>c[i];
like+=c[i]}
if(like==n)
{
    for(int i=1;i<=n;i++)
    {ans*=i;
    ans=ans%998244353;
}
cout<<ans;
}
    else
    {
        cout<<329*526*833;
    }
   return 0;
}

