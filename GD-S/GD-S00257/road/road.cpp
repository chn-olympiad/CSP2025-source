#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define fg cout<<"！！！！！！！！！！！！！！！！！！"<<endl
using namespace std;
const int N=1e4+5,M=1e6+5,mod=998244353;
int n,m,K,tp,cnt;
int fa[N<<1];
ll a[11][N],c[11];
ll ans=1e18,res;
struct node{
	int u,v,id;
	ll w;
}edge[M<<1];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=K;i++){
		cin>>c[i];
		if(c[i]!=0) tp=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(tp==0){
		res=0;
		cnt=M;
		for(int j=1;j<=K;j++){
			res+=c[j];
			for(int k=1;k<=n;k++){
				cnt++;
				edge[cnt].u=n+j;
				edge[cnt].v=k;
				edge[cnt].w=a[j][k];
			}
		}
		for(int j=1;j<=n+K;j++) fa[j]=j;
		sort(edge+1,edge+cnt+1,cmp);
		for(int j=1;j<=cnt;j++){
			int x=find(edge[j].u),y=find(edge[j].v);
			if(x==y) continue;
			fa[x]=y;
			res+=edge[j].w;
		}
		ans=min(ans,res);
	}else{
		for(int i=0;i<(1<<K);i++){
			res=0;
			cnt=M;
			for(int j=1;j<=K;j++){
				if((i>>(j-1))&1){
					res+=c[j];
					for(int k=1;k<=n;k++){
						cnt++;
						edge[cnt].u=n+j;
						edge[cnt].v=k;
						edge[cnt].w=a[j][k];
					}
				}
			}
			for(int j=1;j<=n+K;j++) fa[j]=j;
			sort(edge+1,edge+cnt+1,cmp);
			for(int j=1;j<=cnt;j++){
				int x=find(edge[j].u),y=find(edge[j].v);
				if(x==y) continue;
				fa[x]=y;
				res+=edge[j].w;
			}
			ans=min(ans,res);
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
