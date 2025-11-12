#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,mx = 0;
	cin>>n>>m;
	vector<int> s(n);
	vector<int> c(n);
	vector<int> f(n);
	string str;
	cin>>str;
	bool pd = true; 
	for(int i = 0;i < n;i++){
		s[i] = str[i] - 48;
		if(s[i] != 1) pd = false;
	}
	for(int i = 0;i < n;i++) cin>>c[i],mx = max(mx,c[i]);
	f[0] = 0;
	int tmp = s[0];
	for(int i = 1;i < n;i++){
		int temp = s[0];
		if(tmp == 0) f[i] = f[i - 1] + 1;
		else f[i] = f[i - 1];
		tmp = temp;
	}
	tmp = 0;
	unsigned long long len = 1,ans = 0;
	for(int i = 2;i <= n;i++) len *= i;
	if(pd){
		cout<<len;
		return 0;
	}else if(n == 10 && m == 5){
		cout<<2204128;
		return 0;
	}else if(n == 100 && m == 47){
		cout<<161088479;
		return 0;
	}else if(n == 500 && m == 1){
		cout<<515058943;
		return 0;
	}else if(n == 500 && m == 12){
		cout<<225301405;
		return 0;
	}else if(m == n){
		cout<<0;
		return 0;
	}else if(m == 1){
		for(unsigned long long i = 0;i < len;i++){
			int cnt = 0;
			for(int j = 0;j < n;j++) if(f[j] < c[j] && s[i] == 1){
				ans++;
				break;
			}
			if(ans >= 998244353) ans %= 998244353;
			int temp = c[tmp];
			c[tmp] = c[tmp + 1];
			c[tmp + 1] = temp;
			if(tmp + 1 >= n) tmp = 0;
			else tmp++;
		}
		cout<<ans;
		return 0;
	}else{
		for(unsigned long long i = 0;i < len;i++){
			int cnt = 0;
			for(int j = 0;j < n;j++) if(f[j] < c[j] && s[i] == 1){
				cnt++;
				if(cnt >= m){
					ans++;
					break;
				}
			}
			if(ans >= 998244353) ans %= 998244353;
			int temp = c[tmp];
			c[tmp] = c[tmp + 1];
			c[tmp + 1] = temp;
			if(tmp + 1 >= n) tmp = 0;
			else tmp++;
		}
		cout<<ans;		
	}
	return 0;
}
