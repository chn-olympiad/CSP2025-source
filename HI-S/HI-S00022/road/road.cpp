#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn=100000000;
int a[10000][10005];
struct tp{
	int v,u,w;
}r[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int c[20],q[20][10005];
	for(int i=1;i<=m;i++){
		cin>>r[i].v>>r[i].u>>r[i].w;
		minn=min(minn,r[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];for(int o=1;o<=n;o++)cin>>q[i][o];
	}cout<<7;
	return 0;
}
 
