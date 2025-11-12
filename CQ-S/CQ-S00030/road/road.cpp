#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
}e[1100005];
int p[10020];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int Find(int x){
	if (p[x]==x)
		return x;
	else
		return p[x]=Find(p[x]);
}

long long Kruscal(){
	for (int i=1;i<=n+k;i++)
		p[i]=i;
	long long sum=0;
	sort(e+1,e+m+n*k+1,cmp);
	for (int i=1;i<=m+n*k;i++){
		int pu=Find(e[i].u),pv=Find(e[i].v);
		if (pu!=pv){
			p[pu]=pv;
			sum+=e[i].w;
		}
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	int cnt=0;
	for (int c,i=1;i<=k;i++){
		cin>>c;
		for (int a,j=1;j<=n;j++){
			cin>>a;
			cnt++;
			e[m+cnt]={n+i,j,a};
		}
	}
	cout<<Kruscal();
	
	return 0;
}
