#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long Ans;
struct node{
	int u,v;
	long long len;
}ff[1100005];
int d[10005];
int fa[10015];
int Find(int x){
	if(fa[x]!=x)
		return fa[x]=Find(fa[x]);
	return x;
}
bool cmp(node a,node b){
	return a.len<b.len;
}
void KFC(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(ff+1,ff+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		int x=ff[i].u;
		int y=ff[i].v;
		if(Find(x)!=Find(y)){
			Ans+=ff[i].len;
			fa[x]=y;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>ff[i].u>>ff[i].v>>ff[i].len;
	for(int f,i=1;i<=k;i++){
		cin>>f;
		int hh;
		for(int j=1;j<=n;j++){
			cin>>d[j];
			if(d[j]==0)
				hh=j;
		}
		for(int j=1;j<=n;j++){
			ff[m+(i-1)*n+j].len=d[i];
			ff[m+(i-1)*n+j].u=i;
			ff[m+(i-1)*n+j].v=j;
		}
	}
	KFC();
	cout<<Ans;
	return 0;
}
