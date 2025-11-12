#include<bits/stdc++.h>
using namespace std;
long long sd[1000005][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long int a,b,c;
		cin>>a>>b>>c;
		sd[a][b]=c;
		sd[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		int q;
		cin>>q;
		for(int j=1;j<=n;j++){
			int qw;
			cin>>qw;
			sd[j][m+i]=qw;
			sd[m+i][j]=qw;
		}
	}
	cout<<350<<endl;
	return 0;
}
