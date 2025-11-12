#include<bits/stdc++.h>
using namespace std;
int n,m,k,h[10015],c[15],v[10010],o;
struct edge{
	int t,ne,u;
}f[1200010];
void add(int p,int t,int w,int i){
	f[i].t=t;
	f[i].ne=h[p];
	f[i].u=w;
	h[p]=i;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w,2*i-1);
		add(y,x,w,2*i);
		o+=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			add(n+i,j,w,m+2*i*j-1);
			add(j,n+i,w,m+2*i*j);
		}
	}
	cout<<o;
	return 0;
}
