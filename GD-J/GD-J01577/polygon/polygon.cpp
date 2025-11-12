#include<bits/stdc++.h>
using namespace std;
long long n,a[5140],ans,l;
bool b[5140];
void dfs(int x,long long maxx,long long sum,int id)
{
	if(x==l)
	{
		if(sum>maxx*2) ans++/*,printf("x=%d,sum=%lld,maxx=%lld\n",x,sum,maxx)*/;
		return ;
	}
	for(int i=id;i<=n;++i)
		if(!b[i]) b[i]=true,dfs(x+1,max(maxx,a[i]),sum+a[i],i+1),b[i]=false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(l=3;l<=n;++l)
		dfs(0,0,0,1);
	cout<<ans%998244353;
	return 0;
}
