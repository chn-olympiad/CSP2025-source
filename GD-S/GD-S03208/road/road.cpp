#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+8;
struct node{
	int u,v,w;
}a[N],ans[N];
int n,m,k;
int cnt=0,cntas=0;
int flag[N],c[N],ct[15][N];
int fa[N];
map<pair<int,int>,int> mp;
vector<int> G[N];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	fa[find(x)]=find(y);
}
inline void mem(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
inline bool cmp(node x,node y){
	return x.w<y.w;
}
inline bool check(){
	for(int i=1;i<=n;i++){
		if(find(i-1)!=find(i)){
			return 0;
		}
	}
	return 1;
}
inline int kruskal(){
	sort(a+1,a+cnt+1,cmp);
	int sum=1,answer=0;
	for(int i=1;i<=cnt;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans[++cntas]={u,v,w};
//			cout<<u<<" "<<v<<" "<<w<<endl;
			answer+=w;
			sum++;
			if(sum==n){
				break;
			}
		}
	}
	return answer;
}
inline int Kruskal(){
	int minn=kruskal();
////	cout<<endl<<endl;
//	for(int i=1;i<=cntas;i++){
//		for(int j=i+1;j<=cntas;j++){
////			if(i==j){
////				continue;
////			}
//			int u=ans[i].u,v=ans[i].v,w=ans[i].w;
//			int x=ans[j].u,y=ans[j].v,z=ans[i].w;
//			for(int l=1;l<=k;l++){
//				if(flag[l]&&ct[l][u]+ct[l][y]-max(w,z)<=0){
//					minn+=ct[l][u]+ct[l][y]+c[l]-max(w,z);
//					if(w>z){
//						ans[i]={u,n+l,ct[l][u]};
////						ans[++cntas]={y,n+l,ct[l][y]};
//					}
//					else{
//						ans[j]={y,n+l,ct[l][y]};
////						ans[++cntas]={u,n+l,ct[l][u]};
//					}
////					cout<<l<<" 1 "<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<minn<<endl;
//				}
//				else if(ct[l][u]+ct[l][y]+c[l]-max(w,z)<=0){
//					minn+=ct[l][u]+ct[l][y]+c[l]-max(w,z);
//					flag[l]=1;
//					if(w>z){
//						ans[i]={u,n+l,ct[l][u]};
//						ans[++cntas]={y,n+l,ct[l][y]};
//					}
//					else{
//						ans[j]={y,n+l,ct[l][y]};
//						ans[++cntas]={u,n+l,ct[l][u]};
//					}
////					cout<<l<<" 2 "<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<minn<<endl;
//				}
//			}
//		}
//	}
	return minn;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	mem();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ct[i][j];
		}
	}
	
	
//	for(int i=1;i<=k;i++){
//		int x,w;
//		cin>>x;
//		for(int j=1;j<=n;j++){
//			cin>>w;
//			w+=x;
//			a[++cnt]={n+i,j,w};
//			mp[{n+i,j}]=1;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(i==j){
//				continue;
//			}
//			if(!mp[{i,j}]&&!mp[{j,i}]){
//				a[++cnt]={i,j,0};
//				mp[{i,j}]=1;
//			}
//		}
//	}
	cout<<Kruskal();
	return 0;
}
