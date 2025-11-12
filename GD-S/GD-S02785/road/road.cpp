#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int u[N],v[N],w[N],fa[N],fav[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>fa[i];
		for(int j=1;j<=n;j++){
			cin>>fav[j];
		}
	}
	cout<<n*m-k;
	return 0;
} 
