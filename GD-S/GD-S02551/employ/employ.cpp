#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long n, m;
string s;
long long d[505], c[505];
long long l[15], r[15], ans = 0;
bool f[15] = {0};
void chk(){
	long long alv = 0;
	for(int i = 1;i <= n;i++)
		r[i] = c[l[i]];
	for(int i = 1;i <= n;i++){
		if(d[i] == 0)
			r[i] = 0;
		if(r[i] <= 0)
			for(int j = i + 1;j <= n;j++)
				r[j]--;
	}
	for(int i = 1;i <= n;i++)
		if(r[i] > 0)
			alv++;
	if(alv >= m)
		ans++;
}
void srh(int x){
	if(x == n + 1){
		chk();
		return ;
	}
	for(int i = 1;i <= n;i++)
		if(!f[i])
			f[i] = 1, l[x] = i, srh(x + 1), f[i] = 0, l[x] = 0;
	return ;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		d[i] = s[i - 1] - '0';
	}
	if(m == n){
		bool tf = 1; 
		for(int i = 1;i <= n && tf;i++)
			if(d[i] == 0 || c[i] == 0)
				tf = 0;
		if(tf == 0)
			cout << 0 << endl;
		else{
			long long tot = 1;
			for(long long i = 2;i <= n;i++)
				tot = (tot * i) % mod;
		}
		return 0;
	}
	srh(1);
	cout << ans << endl;
	return 0;
}
