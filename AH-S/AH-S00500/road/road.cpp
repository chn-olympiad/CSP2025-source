#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20000],s[20][20000],ans,M,d,dk,Mans=1e9;
struct node
{
	int x,y,z;
};
vector<node>a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		node c;
		c.x=y,c.y=z;
		a[x].push_back(c);
		c.x=x,c.y=z;
		a[y].push_back(c);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s[i][0];
		for(int j=1;j<=n;j++)
			cin>>s[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		f[i]=1;
		ans=0;
		for(int i=1;i<=n;i++)
			if(!f[i])
			{
				M=1e9,d=0,dk=0;
				int N=a[i].size();
				for(int j=0;j<N;j++)
					if(a[i][j].y<M && f[a[i][j].x])
						M=a[i][j].y,dk=a[i][j].x;
				for(int j=1;j<=k;j++)
					for(int l=1;l<=n;l++)
						if(f[l] && s[j][i]+s[j][k]+s[j][0]<M)
							M=s[j][i]+s[j][k]+s[j][0],d=l,dk=j;
				ans+=M;
				f[i]=1;
				if(dk!=0)
					s[dk][0]=0;
			}
		Mans=min(Mans,ans);
	}
	cout<<Mans;

	return 0;
}
