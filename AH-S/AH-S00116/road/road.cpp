#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,c;
}e[2000005],p[10000005];
int n,m,k,c[15],a[15][10005],path[15],fa[10005];
long long ans=LLONG_MAX;
bool cmp(node n1,node n2){
	return n1.c<n2.c;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
long long f(int len,int nn){
	sort(p+1,p+len+1,cmp);
	int cnt=0;
	long long s=0;
	for(int i=1;i<=len;i++){
		if(find(p[i].u)==find(p[i].v))continue;
		cnt++;
		fa[find(p[i].u)]=find(p[i].v);
		s+=p[i].c;
		if(cnt==nn-1)return s;
	}
	return INT_MAX;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].c;
		p[i]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int kk=1;kk<j;kk++){
				p[++m]={j,kk,a[i][j]+a[i][kk]};
			}
		}
	}
	for(int i=0;i<=n;i++)fa[i]=i;
	ans=min(ans,f(m,n));
	cout<<ans;
	return 0;
}
