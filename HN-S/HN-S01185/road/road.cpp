#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e6+1e5+7;
long long cnt=0,cnt2=0;
struct Edge{
	int x;
	int y;
	long long dis;
}edge[N];
bool cmp(Edge a,Edge b){
	return a.dis<b.dis;
}
int fa[N],sum[N],need[N];
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}
void zu(int a,int b){
	a=find(a);
	b=find(b);
	fa[a]=b;
}
const int M=1e5+7;
int bu[11][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;cnt2=n;
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].dis;
	}
	for(int i=1;i<=k;i++){
		long long p;
		cin>>p;
		need[n+i]=p;
		for(int j=1;j<=n;j++){
			long long v;
			cin>>v;
			edge[++cnt].x=n+i;
			edge[cnt].y=j;
			edge[cnt].dis=(long long)(p+v);
		}
	}
	
	sort(edge+1,edge+cnt+1,cmp);
	long long ans=LONG_LONG_MAX;
//	for(int j=n+1;j<=n+k;j++){
		long long mst=0;
	for(int i=1;i<=cnt;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int x=edge[i].x;int y=edge[i].y;
		if(find(x)!=find(y)){
			zu(x,y);
			sum[x]+=edge[i].dis;
			mst+=edge[i].dis;
		}
	}
	ans=min(ans,mst);
//	for(int i=1;i<=n;i++){
//		if(sum[i]){
//			for(int j=1;j<=n;j++){
//				
//			}
//		}
//	}

	
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
