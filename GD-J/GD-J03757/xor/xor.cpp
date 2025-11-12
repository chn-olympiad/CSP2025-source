#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll a[N];
struct node{
	int x,y;
}dp[N];
bool cmp(node a,node b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt = 1;
	for(int i=1;i<=n;i++){
		int ans = a[i];
		if(ans == k){
			dp[cnt].x = i;
			dp[cnt].y = i;
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			ans  = ans^a[j];
			if(ans == k){
				dp[cnt].x = i;
				dp[cnt].y = j;
				cnt++;
				break;
			}
		}
	}
	sort(dp+1,dp+cnt,cmp);
	int maxn = 0;
	int r = dp[1].y;
	for(int i=1;i<cnt;i++){
		if(i == 1) maxn++;
		else{
			if(dp[i].x<=r) continue;
			else{
				maxn++;
				r = dp[i].y;
			}
		}
	}
	cout<<maxn;
	return 0;
}
