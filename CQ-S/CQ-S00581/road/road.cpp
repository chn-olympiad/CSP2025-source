#include<bits/stdc++.h>
#define int long long
using namespace std;
struct bian{
	int u,v,w;
}a[1000010];
int n,m,k,cnt;
//vector<pair<int,int> >a[1010];
int c[15];
int fa[1000010];
int find(int x){
	if(fa[x]==x)return x;
	else fa[x]=find(fa[x]);
}
bool cmp(bian a,bian b){
	return a.w<b.w;
}
void kruskal(){
	int sum=0,cct=0;
	for(int i=1;i<=cnt;i++){
		int x=a[i].u,y=a[i].v,z=a[i].w;
		if(find(x)!=find(y)){
			fa[x]=find(y);
			sum+=z;
			cct++;
			if(cct==n-1){
				cout<<sum;
				exit(0);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
//		int u,v,w;
		cin>>a[i].u>>a[i].v>>a[i].w;
//		a[u].push_back({v,w});
//		a[v].push_back({u,w});
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i=1;i<=n;i++){
			cin>>a[m+i].w;
			a[m+i].u=i,a[m+i].v=++cnt;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	kruskal();
	return 0;
}
