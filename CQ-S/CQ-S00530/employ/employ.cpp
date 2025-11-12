#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],k[1000],su,f[1000],ovo;
string s;
void dfs(int d,int p,int l){
	if(d > n){
		return ;
	}
	if(c[p] <= k[d] + ovo){
		ovo++;
	}
	if(l == m){
		su++;
		su = su % 998244353;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(f[i] == 0){
			f[i] = 1;
			if(s[i] == '1'){
				dfs(d + 1,i,l + 1);
			}else{
				dfs(d + 1,i,l);
			}
			f[i] = 0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	int summ = 0;
	for(int i = 0;i < s.size();i++){
		summ += s[i] - 48;
	}
	if(summ < m){
		cout << 0;
		return 0;
	}
	int len = s.size();
	if(summ == len){
		int realn = 0;
		for(int i = 1;i <= n;i++){
			if(c[i] > 0){
				realn++;
			}
		}
		if(realn < m){
			cout << 0;
			return 0;
		}
		int res = 1;
		for(int i = 1;i <= m;i++){
			res = res * i % 998244353;
		}
		cout << res;
		return 0;
	}
	s = 'a' + s;
	for(int i = 1;i <= len;i++){
		if(s[i] == '1'){
			k[i] = k[i - 1] + 1;
		}else{
			k[i] = k[i - 1];
		}
	}
	for(int i = 1;i <= n;i++){
		f[i] = 1;
		dfs(1,i,0);
		f[i] = 0;
	}
	cout << su;
	return 0;
}
/*
\(owo)/
*/
