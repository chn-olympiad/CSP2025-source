#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
struct node{
	int u,v,w;
	bool operator<(const node&K){
		return w<K.w;
	}
}rd[1100000];
int n,m,k,fa[N];
int c[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n+k;i++)fa[i]=i;
	int tall;
	for (int i=1;i<=m;i++){
		cin>>rd[i].u>>rd[i].v>>rd[i].w;
	}
	tall=m;
	for (int i=1;i<=k;i++){
		int num=m+i;
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>rd[++tall].w;
			rd[tall].u=num;rd[tall].v=j;
		}
	}
	sort(rd+1,rd+tall+1);
//	for (int i=1;)
	
	return 0;
}
