#include "bits/stdc++.h"
using namespace std;
int loss[100005];
struct node{
	int pos, num;
};
bool cmp(node a, node b){
	return a.num <= b.num;
}
int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while (t--){
		int n;
		int a, b, c;
		long long sum = 0;
		cin>>n;
		if (n == 2){
			node one[3], two[3];
			cin>>one[0].num>>one[1].num>>one[2].num;
			cin>>two[0].num>>two[1].num>>two[2].num;
			for (int i=0;i<=2;i++){
				one[i].pos = i, two[i].pos = i;
			}
			sort(one, one+2, cmp), sort(two, two+2, cmp);
			if (one[2].pos != two[2].pos) cout<<one[2].num+two[2].num<<endl;
			else{
				if (one[2].num > two[2].num){
					cout<<one[2].num+two[1].num<<endl;
				}
				else
					cout<<one[1].num+two[2].num<<endl;
			}
			continue;
		}
		for (int i=1;i<=n;i++){
			cin>>a>>b>>c;
			loss[i] = a-b;
			sum += b;
		}
		int dp[n+1][n/2+1];//dp[i][j]表示考虑前i个成员，装j个时的最大值 
		//dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+loss[i])
		memset(dp, 0, sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n/2&&j<=i;j++){
				if (i==j) dp[i][j] = dp[i-1][j-1] + loss[i];
				else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+loss[i]);
			}
		}
		cout<<dp[n][n/2]+sum<<endl;
	}
	fclose(stdin), fclose(stdout);
}
