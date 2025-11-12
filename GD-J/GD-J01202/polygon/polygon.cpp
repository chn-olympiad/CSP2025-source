#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long y=0;
int maxx=0,s,n,a[5005],d=0;
bool v[5005];
void dfs(int x,int h)
{
	if(x>3)
	{
		if(s>maxx*2)
		{
			y++;
			y=y%mod;
		}
	}
	if(x==n+1)return;
	for(int i=h;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			int h=maxx;
			maxx=max(maxx,a[i]);
			s+=a[i];
			dfs(x+1,i+1);
			s-=a[i];
			maxx=h;
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,1);
	printf("%lld",y);
	
	return 0;
}
