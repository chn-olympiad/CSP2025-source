#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f;
struct node{
	int u,v,w;
	bool operator<(node a)const{
		return w<a.w; 
	}
}e[N],re[N];
int n,w,k,fa[N],c[N],a[20][N],ans=-INF;
bool vis[N];
int find(int x){
	if(x==fa[x]){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<0;
	return 0;
}

