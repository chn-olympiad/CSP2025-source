#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000005],c[1000005];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
	}
	if(m==1){
		sort(c+1,c+n+1,greater<int>() );
		int pos = 0;
		for(int i = 0; i < n; i ++){
			if(s[i]=='1'){
				pos = i;
				break;
			}
		}
		for(int i = 1; i <= n; i ++){
			if(c[i]<i){
				long long ans = 1;
				for(int j = i-1; j >= 2; j++){
					ans = (ans * j) % 998244353;
				}
				long long mul = 1;
				for(int j = n-i+1;j>=2;j--){
					mul = (mul * j)%998244353;
				}
				cout << ans * mul;
				return 0;
			}
		}
		int mul = 1;
		for(int j = 1; j <= n; j ++){
			mul = (mul * j) % 998244353;
		}
		cout << mul;
		return 0;
	}
	if(m==n)
	{
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				cout << 0;
				return 0;
			}
		}
		int mul = 1;
		for(int j = 1; j <= n; j ++){
			mul = (mul * j) % 998244353;
		}
		cout << mul;
		return 0;
	}
	int flag = 1;
	for(int i = 0; i < n; i ++){
		if(s[i] == '0'){
			flag = 0;
			break;
		}
	}
	if(flag){
		int mul = 1;
		for(int j = 1; j <= n; j ++){
			mul = (mul * j) % 998244353;
		}
		cout << mul;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		a[i] = i;
	}
	do
	{
		int cnt1 = 0,cnt2=0;
		for(int i = 1; i <= n; i ++){
				//cout << a[i] << ' ';
			if(cnt1<c[a[i]] && s[a[i]-1]=='1'){
				cnt2++;
				//cout << a[i] << ' ';
			}
			else cnt1 ++;
		}
		if(cnt2 >= m)ans++;
		//cout << endl;
	}while(next_permutation(a+1,a+n+1));
	cout << ans;
	return 0;
}
