#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v,u,w,c,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>v>>u>>w;
		c+=w;
	}
	for(long long i=1;i<=n;i++){
		cin>>c;
		for(long long j=1;j<=n;j++){
			cin>>a;
		}
	}
	cout<<w;
}
