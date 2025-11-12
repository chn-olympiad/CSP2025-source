#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n , ans , m , a[505] , cnt;
bool s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		char c;cin >> c;
		s[i] = c - '0' , cnt += s[i];
	}
	for(int i=1;i<=n;i++)cin >> a[i] , a[i] = a[i] * 1000 + i;
	if(!cnt){
		cout << 0;
		return 0;
	}
	if(m==1){
		int sum = 0 , tmp = 1 , fir;
		for(int i=1;i<=n;i++){
			if(s[i]){
				fir = i;
				break;
			}
		}
		for(int i=1;i<=n;i++)sum += ((a[i] / 1000) >= fir);
		for(int i=n-1;i>1;i--)tmp *= i , tmp %= mod;
		cout << (sum * tmp) % mod;
		return 0;
	}
	sort(a+1,a+n+1);
	do{
		int tim = 0 , sum = 0;
		for(int i=1;i<=n;i++){
			if(tim>=(a[i]/1000))tim++;
			else if(!s[i])tim++;
			else sum++;
		}
		ans += (sum >= m) , ans %= mod;
	}while(next_permutation(a+1,a+n+1));
	cout << ans;
	return 0;
}

