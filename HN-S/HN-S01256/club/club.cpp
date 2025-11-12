#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,ans,sum;
int a[N][5],b[N];
void dfs(int x,int ct,int c1,int c2,int c3)
{
	if(c1>n/2||c2>n/2||c3>n/2) return ;
	if(ct+b[x+1]<ans) return ;
	if(x==n)
	{
		ans=max(ans,ct);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1) dfs(x+1,ct+a[x+1][i],c1+1,c2,c3);
		else if(i==2) dfs(x+1,ct+a[x+1][i],c1,c2+1,c3);
		else if(i==3) dfs(x+1,ct+a[x+1][i],c1,c2,c3+1);
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=max(a[i][1],max(a[i][2],a[i][3]));
			
		}
		b[n+1]=0;
		for(int i=n;i>=1;i--) b[i]+=b[i+1];
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
