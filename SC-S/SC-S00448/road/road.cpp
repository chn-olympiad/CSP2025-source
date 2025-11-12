#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[10015][10015];
int c[10015];
struct R{
	int st,en,h;
};
queue<R> q;
int fl[10015];
int anss[10015][10015];
int flag[10015];
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y; 
		cin>>x>>y;
		cin>>w[x][y];
		w[y][x]=w[x][y];
	}
	for(int i=1;i<=k;i++)
	{
		int t=n+i;
		cin>>c[t];
		for(int i=1;i<=n;i++)
		{
			cin>>w[t][i];
			w[i][t]=w[t][i];
		}
	}
	for(int i=2;i<=n+k;i++)
	{
		anss[1][i]=1e9+1;
	}
	fl[1]=1;
	for(int i=1;i<=n+k;i++)
	{
		if(w[1][i]!=0)
		{
			R t;
			t.st=1;
			t.en=i;
			t.h=0;
			t.h+=w[1][i];
			anss[1][i]=t.h;
			q.push(t);
		}
	}
	while(!q.empty())
	{
		R t=q.front();
		q.pop();
		for(int i=1;i<=n+k;i++)
		{
			R tt;
			if(w[t.en][i]!=0&&i!=t.st)
			{
				tt.st=t.st;
				tt.en=i;
				tt.h=t.h;
				tt.h+=w[t.en][i];
				if(i>n)
				{
					tt.h+=c[i];
					flag[i]++;
				}
				if(anss[tt.st][i]>=tt.h)
				{
					anss[tt.st][i]=tt.h;
					tt.h-=c[i];
					q.push(tt);
				}
				else
				{
					flag[i]--;
				}
			}
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		cout<<1<<" "<<i<<" "<<anss[1][i]<<"\n";
		ans=ans+anss[1][i];
	}
	for(int i=n+1;i<=n+k;i++)
	{
		cout<<c[i]<<"\n";
		if(flag[i]!=0)
		{
			ans=ans+c[i];
		}
	}
	cout<<ans;
	return 0;
}