#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,ans=0;
struct TAT{
	int u,v,w;
}R[2000005],r[1000005];
int V[11][10005];
long long Min=0x3fffffff;
int cmp(TAT a,TAT b){
	return a.w<b.w;
}
int CMP(TAT a,TAT b){
	return a.u<b.u;
}
int Cmp(TAT a,TAT b){
	return a.v<b.v;
}
int dfs(int i,int j,int Flag){
	if(Flag==n*2)return 0;
	if(i==R[j].v) return 1;
	else dfs(i,R[j].v,Flag+1);
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>R[i].u>>R[i].v>>R[i].w;
		ans+=R[i].w;
		r[i].u=R[i].u;
		r[i].v=R[i].v;
		r[i].w=R[i].w;
		R[i+n].u=R[i].v;
		R[i+n].v=R[i].u;
		R[i+n].w=R[i].w;
	}
	sort(r+1,r+n+1,cmp);
	sort(R+1,R+n+1,Cmp);
	sort(R+1,R+n+1,CMP);
	for(int i=1;i<=k;i++){
		cin>>V[i][0];
		if(V[i][0]==0) sum++;
		for(int j=1;j<=n;j++){
			cin>>V[i][j];
			if(V[i][j]==0) sum++;
		}
	}
	for(int i=1;i<=m;i++){
		if(dfs(R[i].u,R[i].v,1)==1) ans-=R[i].w;
	}
	if(sum==k*(n+1)) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
