#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],res[N];
bool b[N];
ll n,m,ans,sum,maxn;
void dfs(ll dep,ll len)
{
	if(dep==len+1)
	{
		if(sum>maxn*2) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i]) 
		{
			ll maxx=maxn;
			maxn=max(maxn,a[i]);
			b[i]=1;
			sum+=a[i];
			dfs(dep+1,len);
			sum-=a[i]; 
			b[i]=0;
			maxn=maxx;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
		res[i]=ans-res[i-1];
		ll add=1;
		for(int j=1;j<=i;j++) add*=j;
//		cout<<ans<<' ';
		ans-=res[i]/add*(add-1);
		res[i]=ans;
//		cout<<ans<<' ';
//		cout<<res[i]<<endl;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
1 2 3 4 5
*/
