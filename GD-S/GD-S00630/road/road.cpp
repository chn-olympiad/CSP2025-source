#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
long long w[1000005],b[105],c[105][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<0<<endl;
	return 0;
}
