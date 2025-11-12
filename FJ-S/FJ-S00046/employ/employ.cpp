#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n,m,a[510];
string str;

map <int,int> mp;

int main(){
	freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	scanf("%d%d",&n,&m);
	cin >> str;
	bool bol = true;
	int cnt3 = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(mp.count(a[i])){
			mp[a[i]]++;
		}else{
			mp[a[i]] = 1;
		}
		if(str[i - 1] == '0'){
			bol = false;
		}else{
			cnt3++;
		}
	}
	if(bol){
		long long ans = 1;
		for(int i = 2;i <= n;i++){
			ans *= i * 1LL;
			ans %= mod;
		}
		printf("%lld",ans % mod);
		return 0;
	}
	if(cnt3 < m){
		printf("0");
		return 0;
	}
//	else if(cnt3 == m){
//		long long ans = 1;
//		for(int i = n;i > n - cnt3;i--){
//			ans *= i;
//			ans %= mod;
//		}
//		printf("%lld",ans % mod);
//		return 0;
//	}
	sort(a + 1,a + n + 1);
	long long ans = 0;
	int cnt,cnt2;
	do{
		cnt = cnt2 = 0;
		for(int i = 1;i <= n;i++){
			if(str[i - 1] == '0'){
				cnt++;
			}else{
				if(cnt >= a[i]){
					cnt++;
				}else{
					cnt = 0;
					cnt2++;
				}
			}
		}
		if(cnt2 >= m){
			ans++;
			ans %= mod;
		}
	}while(next_permutation(a + 1,a + n + 1));
	for(auto i : mp){
		for(int j = 2;j <= i.second;j++){
			ans *= j;
			ans %= mod;
		}
	}
	printf("%lld",ans % mod);
	return 0;
}
