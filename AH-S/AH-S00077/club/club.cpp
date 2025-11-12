#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int n;
bool cmp(int x,int y)
{
	return x>y;
}
int ans=0;
void dfs(int p,int as,int bs,int cs,int s)
{
	if(p==n+1)
	{
		ans=max(ans,s);
		return ;
	}
	if(as+1<=n/2)dfs(p+1,as+1,bs,cs,s+a[p]);
	if(bs+1<=n/2)dfs(p+1,as,bs+1,cs,s+b[p]);
	if(cs+1<=n/2)dfs(p+1,as,bs,cs+1,s+c[p]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int oka=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0||c[i]!=0)
			{
				oka=0;
			}
		}
		if(oka==1)
		{
			sort(a+1,a+n+1,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans;
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

