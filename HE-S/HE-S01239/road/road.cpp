//¿ª´óÄÚ´æ 
#include <bits/stdc++.h>
#define N 20010
#define M 2000010
#define int long long
using namespace std;
struct node{
	int u,v,w;
}edge[M];
int con[20][N],c[N],a[N],fa[N];
int n,m,k,sum;
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void kru(){
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int p=find(u),q=find(v);
		if(p==q) continue;
		fa[p]=fa[q];
		sum+=w;
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=0;
		bool tg=0;
		for(int j=1;j<=n;j++){
			cin>>con[i][j];
			if(con[i][j]==0){
				tg=1;
				a[i]=j;
			} 
		}
		f&=tg;
	}
	if(k==0){
		sort(edge+1,edge+1+m,cmp);
		kru();
		cout<<sum<<'\n';
	}
	else if(f){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j==a[i]) continue;
				edge[++m].u=j,edge[m].v=a[i],edge[m].w=con[i][j];
			}
		}
		sort(edge+1,edge+1+m,cmp);
		kru();
		cout<<sum<<'\n';
	}
	else{;
	//	for(int i=1;i<=k;i++){
	//		for(int j=1;j<=n;j++){
	//			
	//		}
	//	}
	}
	return 0;
}
