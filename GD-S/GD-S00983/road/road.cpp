#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt,head[100005],ans;
struct node{
	int to,nxt,w;
}e[100005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
