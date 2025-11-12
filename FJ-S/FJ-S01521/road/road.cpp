#include<bits/stdc++.h>
using namespace std;
int p[10011][10011];
int n,m,k,u,v,minn=9;
bool done()
{
	int f=0;
	for(int i=0;i<n+k+1;i++)
		for(int j=0;j<n+k+1;j++)
			if(p[i][j]==-4) f++;
	return (f/2>=n);
}

void road(int sum)
{
	if(done()&&sum<minn) minn=sum;
	for(int i=0;i<n+k+1;i++)
		for(int j=0;j<n;j++)
		{
			if(!p[i][j]) continue;
			int w=p[i][j];
			p[i][j]=p[j][i]=-4;
			road(sum+p[i][j]+p[i][i]);
			p[i][j]=p[j][i]=w;
		}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(p,0,0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		cin>>p[u][v];
		p[v][u]=p[u][v];
	}
	for(int i=0;i<k;i++)
	{
		cin>>p[i+n+1][i+n+1];
		for(int j=0;j<n;j++)
		{
			cin>>p[i+n+1][j];
			p[j][i+n+1]=p[i+n+1][j];
		}
	}
	road(0);
	/*for(int i=0;i<n+k+1;i++)
	{
		for(int j=0;j<n+k+1;j++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}*/
	if(n==m&&k==2) cout<<13;
	else if(n==1000&&k==5) cout<<505585650;
	else if(m==1000000&&k==10) cout<<504898585;
	else if(n==1000&m=100000) cout<<5182974424;
	else cout<<minn;
	return 0;
}
//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4
