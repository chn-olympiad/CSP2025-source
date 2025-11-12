#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[20000][20000];
long long ans;
int p[20];
bool v[20000];
int z[20000];
int w[20000];
void dijkstra()
{
	queue<int>q;
	q.push(1);
	v[1]=1;
	while(!q.empty())
	{
		int l=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(s[l][i]!=-1)
			{
				if(v[i]==0)
				{
					v[i]=1,z[i]=z[l]+s[l][i];
					w[i]=l;
					q.push(i);
				}
				else if(z[l]+s[l][i]<z[i])
				{
					z[i]=z[l]+s[l][i];
					w[i]=l;
					q.push(i);
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		for(int j=1;j<=n+k;j++)
		s[i][j]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		s[a][b]=s[b][a]=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>p[i];
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			s[n+i][j]=s[j][n+i]=a;
		}
	}
	n+=k;
	dijkstra();
	for(int i=1;i<=n-k;i++)
	{
		ans+=z[i];
	}
	cout<<ans<<endl;
	return 0;
}
