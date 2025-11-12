#include<bits/stdc++.h>
using namespace std;
const int N = 2e4;
int n,m,ans;
int a[N];
int dp[N][N]; // i开始，共j个 
struct node{
	int l,r;
};
vector<node>line;

bool pd(int l ,int r) {
	for( auto e : line ) {
		if(l <= e.r && l >= e.l) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			dp[i][j] = dp[i][j-1] ^ a[j];
//			cout<<i<<' '<<j;
			if(dp[i][j] == m && pd(i, j)) {
				line.push_back({i,j});
//				cout<<"YES";
				ans++;
			}
//			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
}
