#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,q;
int m;
string s;
int g = 0;
int tot;
long long ans = 1;
int a[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < s.size();i ++)if(s[i] == '1')tot ++;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] == 0)g ++;
	}
	if(n - g < m){
		puts("0");
		return 0;
	}
	else {
		for(int i = 1;i <= n;i ++){
			ans = (long long)(ans * i);
			ans %= mod;
		}
		cout << ans;
	}
	return 0;
}
