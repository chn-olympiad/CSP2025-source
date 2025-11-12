#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[10000],b[10000],n,ans;

void dfs(int need,int l,int now)
{
	if(!need)
	{
		now--;
		int h=0,m=b[now];
		for(int j=1;j<=now;j++) h+=b[j];
		if(h>m*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	need--;
	for(int i=l+1;i<=n-need;i++)
	{
		b[now]=a[i];
		dfs(need,i,now+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(i,0,1);
	cout<<ans;
	return 0;
}
