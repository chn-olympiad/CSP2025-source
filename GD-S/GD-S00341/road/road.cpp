#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11][10001],f[10001],ok[10001],cnt;
struct node{
	int u,v,w;
}e[10000001];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int work(){
	long long res=0;
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int r1=find(u),r2=find(v);
		if(r1!=r2){
			res+=w;
			f[r2]=r1;
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}	
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) ok[++cnt]=j;
		}
		for(int j=1;j<=cnt;j++){
			int v=ok[j];
			for(int l=1;l<=n;l++){
				e[++m]={v,l,a[i][l]};
			}
		}
	}
	cout<<work()<<endl;
}
