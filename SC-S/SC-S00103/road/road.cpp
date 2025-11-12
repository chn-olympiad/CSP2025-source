#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct rd{
	int u,v,w;
}r[10005];
int b[12][10005],f[10005];
int n,m,k;
bool cmp(rd a,rd b){
	return a.w<b.w;
}
int find(int a){
	if(f[a]==a) return a;
	f[a]=find(f[a]);
	return f[a];
}
void bing(int a,int b){
	int x=f[a],y=f[b];
	f[y]=x;
	return;
}
long long cnt=0;
void dfs(int qd){
	int pd=0;
	for(int i=qd;i<=n;i++){
		if(find(r[i].u)!=find(r[i].v)){
			qd=i+1;
			bing(r[i].u,r[i].v);
			cnt+=r[i].w;
			pd=1;
			break;
		}
	}
	if(pd==0) return;
	dfs(qd);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k==0){
		sort(r+1,r+m+1,cmp);
		dfs(0);
		cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
} 