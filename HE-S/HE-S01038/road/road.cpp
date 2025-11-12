#include<bits/stdc++.h>
using namespace std;
int u[100010],v[100010],w[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		cnt+=w[i];
	}
	cout<<cnt;
	return 0;

}
