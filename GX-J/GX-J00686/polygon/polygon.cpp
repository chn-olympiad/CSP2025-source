#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n,ans=0,bc=2,maxn=0,zc;
cin>>n;
for(long long i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+1+n);
for(long long i=1;i<=n;i++)
{
    bc=2;
    while(n-i>=bc)
    {
        zc=a[i];
        maxn=a[i];
        for(long long x=i+1;x<=n-bc+1;x++)
        {
            for(long long y=x;y<=bc;y++)
            {
                zc+=a[y];
                maxn=max(a[y],maxn);
            }
            if(2*maxn<zc)ans++;
        }
        bc++;
    }
}
cout<<ans;
return 0;
}
