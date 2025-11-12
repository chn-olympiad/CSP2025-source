#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
long long n,m,x,ans=1;
long long s[501],r[501];
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
x=n;
for(int i=1;i<=n;i++)cin>>s[i];
for(int i=1;i<=n;i++){cin>>r[i];if(r[i]==0)x--;}
for(int i=1;i<=x;i++)
{ans=(i*ans)%998244353;}
cout<<ans;
return 0;
}
