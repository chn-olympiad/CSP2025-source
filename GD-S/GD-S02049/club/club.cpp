#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll one,two,three;
}a[100005];
ll t,n,dp[100005];
bool s(node x,node y){
	if(x.one == y.one){
		if(x.two == y.two){
			return x.three > y.three;
		}
		return x.two > y.two;
	}
	return x.one > y.one;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].one >> a[i].two >> a[i].three;
		}
		ll n1 = 0,n2 = 0;
		for(int i = 1;i <= n;i++){
			if(n1 <= n / 2){
				dp[i] = max(dp[i - 1] + a[i].one,max(dp[i - 1] + a[i].two,dp[i - 1] + a[i].three);
				n1++;
			}else if
		}
		cout << dp[n] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
