#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1000050;
int n,m,k;
long long ans;
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int x,y,w;
}e[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
void kru(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int xx=find(e[i].x),yy=find(e[i].y);
		if(xx!=yy){
			fa[xx]=yy;
			ans+=e[i].w;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	kru();
	cout<<ans<<"\n";
	return 0;
}

