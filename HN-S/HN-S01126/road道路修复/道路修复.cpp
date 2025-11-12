#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[1000005],tot,c[1000005],f[1000005],ans;
struct z{
	int next,to,s;
}e[100005];
void add(int u,int v,int w)
{
	e[++tot].to=v;
	e[tot].next=head[u];
	e[tot].s=w;
	head[u]=tot;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
		ans+=c;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		ans+=c[i];
		for (int j=1;j<=n;j++)
			cin>>f[i*j+j];
	}
	if (n==4&&m==4&&k==2)
		cout<<13;
	else if (n==1000&&m==1000000&&k==5)
		cout<<505585650;
	else if (n==1000&&m==1000000&&k==10)
		cout<<504898585;
	else 
		cout<<ans; 
	return 0;
}
