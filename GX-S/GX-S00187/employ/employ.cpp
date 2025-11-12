#include<bits/stdc++.h>
using namespace std;
#define MAXN 998244353
long long n,m,ans,cnt,mod=MAXN,sum=1,x,y;
char a;
int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a;
if(a=='1') ans++;
if(a=='0') cnt++;
}
for(int i=1;i<=n;i++)
{
	cin>>x;
	if(x==0)y++;
	
}
if(ans-y<m)
{
cout<<0;
}
else if(ans-y>=m)
{
for(int i=2;i<=ans-y;i++)
{
sum*=i;
sum%=mod;
}
cout<<sum;
}

return 0;
}
