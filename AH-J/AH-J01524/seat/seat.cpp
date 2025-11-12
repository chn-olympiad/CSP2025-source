#include <bits/stdc++.h>
using namespace std;
int a[10000][10000];
int dp[10000][10000];
vector<int> vec;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			vec.push_back(a[i][j]);
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				vec[i]=dp[i][j];
			}
		}
		else{
			for(int j=1;j<=m;j++){
				vec[i]=dp[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==a[1][1]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
