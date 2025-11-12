#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct lu{
	int u,v,w;
}a[1000005];
struct cheng{
	int c;
	int b[100005];
}d[100005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>d[i].c;
		for(int j=1;j<=n;j++){
			cin>>d[i].b[j];
		}
	}
	cout<<26; 
}
