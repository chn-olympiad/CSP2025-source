#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10015],z[15],op=1,fg[15];
long long ans=1e18;
int read(){
	int cnt=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')cnt=(cnt<<1)+(cnt<<3)+c-'0',c=getchar();
	return cnt;
}
struct node{
	int x,y,id;
	long long z;
}e[1100005];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void kruskal(long long d){
	long long cnt=d;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=m+n*k;++i){
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y||fg[e[i].id])continue;
		fa[y]=x;
		cnt+=e[i].z;	
	}
	ans=min(ans,cnt);
	return;
} 
void dfs(int d,long long sum){
	if(d>k){
		kruskal(sum);
		return;
	}
	fg[d]=1;
	dfs(d+1,sum);
	fg[d]=0;
	dfs(d+1,sum+z[d]);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=k;++i){
		int d;
		z[i]=read();
		op&=(z[i]==0);
		for(int j=1;j<=n;++j){
			d=read();
			e[m+(i-1)*n+j]={i+n,j,i,d};
		}
	}
	sort(e+1,e+m+n*k+1,cmp);
	if(k==0){
		for(int i=1;i<=m;++i){
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y)continue;
			fa[y]=x;
			ans+=e[i].z;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
