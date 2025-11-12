#include<bits/stdc++.h>
using namespace std;
long long n,k,x[500005],a[500005],dp[500005],i,j,m;
struct node{
	long long l;
	long long r;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<node>v;
	cin >> n >> k;
	cin >> a[1];
	x[1] = a[1];
	for(i=2;i<=n;i++){
		cin >> a[i];
		x[i] = x[i-1] xor a[i];
	}
	if(n <= 9000){
		for(i=1;i<=n;i++){
			if(x[i] == k){
				v.push_back({1,i});
				m++;
			}
		}
		for(i=2;i<=n;i++){
			for(j=i;j<=n;j++){
				if((x[j] xor x[i-1]) == k){
					v.push_back({i,j});
					m++;
				}
			}
		}
		dp[0] = 1;
		for(i=1;i<m;i++){
			dp[i] = dp[i-1];
			for(j=0;j<i;j++){
				if(v[j].r < v[i].l){
					dp[i] = max(dp[i],dp[j]+1);
				}
				else dp[i] = max(dp[i-1],dp[i]);
			}
		}
		cout << dp[v.size()-1];
	}
	return 0;
}



