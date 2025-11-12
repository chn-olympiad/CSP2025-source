#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+1e5+10;
int n,m,k;
struct node{
	int u,v,w,ty;
}r[M];
int a[15][N],c[20];
int fa[N],cp[N];
int find(int a){
	if(fa[a]==a){
		return a;
	}else{
		return fa[a]=find(fa[a]);
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve1(){
	long long ans=0,cnt=0;
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=m;i++){
		int from=r[i].u,to=r[i].v;
		if(find(from)!=find(to)){
			ans+=r[i].w;
			cnt++;
			fa[find(from)]=find(to);
		}else{
			continue;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)cp[i]=j;
		}
	}
	for(int i=1;i<=k;i++){
		int uu=cp[i];
		for(int j=1;j<=n;j++){
			if(j==uu)continue;
			r[++m].u=uu;
			r[m].v=j;
			r[m].w=a[i][j];
		}
	}
	solve1();
	return 0;
} 
