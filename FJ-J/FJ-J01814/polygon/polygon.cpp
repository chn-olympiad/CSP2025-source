#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//----------------------
lld n,a[5050];
lld sum=0,mod=998244353;
bool cmp(int x,int y)
{
	return x<y;
}
void dfs(int k,lld val,int cnt)
{
	if(k==n)
	{
		if(cnt>=3)
		{
			++sum;
			sum%=mod;
		}
		return;
	}
	
	dfs(k+1,val,cnt);
	
	if(val>a[k+1]||cnt<2)
	{
		dfs(k+1,val+a[k+1],cnt+1);
	}
	
	return;
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1,cmp);
		for(int i=1;i+2<=n;++i)dfs(i-1,0,0);
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*



5
1 2 3 4 5





*/
