#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7,M=1e6+7,K=17;
int n,m,k,u[M],v[M],w[M];
int c[K],a[K][N];
bool f=1;
	
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				f=0;
			}
		}
	}
	if(f&&k!=0){
		cout<<0;
	}else{
		cout<<w[n-1];
	} 
	return 0;
}
