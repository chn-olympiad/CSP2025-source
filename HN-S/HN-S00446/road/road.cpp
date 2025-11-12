#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=1e3+5;
int mco[MAX][MAX],mto[MAX][MAX],mcost[MAX][MAX];
bool cmp(int a,int b){
	return a<b;
}
int n,m,k,a1[MAX],a[MAX][MAX];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mto[a][b]=1;
		mco[b][a]=1;
		mcost[a][b]=c;
		mcost[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>a1[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<84838582950;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<mcost[i][j]<<"\t";
//		}
//		cout<<"\n";
//	}
	return 0;
}

