#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int dp[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,rstart,wc[11],rend,w;
	cin>>n>>m>>k;int s;
	for(int i=1;i<=m;i++){
		cin>>rstart>>rend>>w;
		dp[rstart][rend]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>wc[i];s+=wc[i];
		for(int j=1;j<=n;j++){
			cin>>dp[m+1][j];
		}
	}
	cout<<s;
	return 0;
}
