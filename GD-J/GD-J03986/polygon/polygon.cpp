#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 998244353;
ll n,cnt=0;
ll a[5005],dp[5005]; 
unsigned long long s[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(ll i = 1; i<=n; i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}
	sort(s+1,s+n+1);
	
	if(n<3){
		cout << 0 << endl;
		return 0;
	}else if(n==3){
		if(a[1] + a[2] > a[3])
			cout << 1 <<endl;
		else cout << 0 << endl;
		return 0;
	}
	for(ll i = 3; i<=n; i++){
		ll l=1,r=2;
		cnt=0;
		while(r<i){
			while(s[r] - s[l-1] <= a[i] && r<i) r++;//找第1个符合条件的区间 
			if(i==r)break;//找不到就break; 
			while(s[r] - s[l-1] > a[i] && l<r){//试探底线 
				cnt++;
				l++;
			}
			if(l==r)r++;
		}
		dp[i] = (dp[i-1]+cnt)%mod;
	}
	cout << dp[n];
	return 0;
}

/*
5 
2 2 3 8 10

*/
