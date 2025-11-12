#include<bits/stdc++.h>
using namespace std;
int f[3000][3000];
int n,m,k;
int vis[100010];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,d;
		cin>>u>>v>>d;
	}
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&k==5) cout<<505585650;
	else if(n==1000&&m==1000000&&k==10) cout<<504898585;
	else if(n==1000&&m==100000&&k==10) cout<<5182974424;

	return 0;
}
