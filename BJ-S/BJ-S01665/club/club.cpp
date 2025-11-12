#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,a[100005][3],ans;
void dfs(int x,int y,int u,int v,int w,long long sum)
{
	if(x<n)
	{
		if(u+1<=n/2)
			dfs(x+1,0,u+1,v,w,sum+a[x][y]);
		if(v+1<=n/2)
			dfs(x+1,1,u,v+1,w,sum+a[x][y]);
		if(w+1<=n/2)
			dfs(x+1,2,u,v,w+1,sum+a[x][y]);
	}
	else
	{
		int i=u<n/2?a[x][0]:0,j=v<n/2?a[x][1]:0,k=w<n/2?a[x][2]:0;
		ans=max(ans,sum+max(i,max(j,k)));
		return;
	}
}
int c[100001];
bool cmp(int i,int j){return i>j;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans=0;
		bool A=true;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			c[i]=a[i][0];
			if(!(a[i][1]==0&&a[i][2]==0))
				A=false;
		}
		if(A)
		{
			sort(c+1,c+n+1,cmp);
			for(int i = 1;i<=n/2;i++)
				ans+=c[i];
			cout << ans << endl;
			continue;
		}
		dfs(1,0,1,0,0,0);
		dfs(1,1,0,1,0,0);
		dfs(1,2,0,0,1,0);
		cout << ans << endl;
	}
	return 0;
}
