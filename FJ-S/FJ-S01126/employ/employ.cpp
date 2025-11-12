#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >>n >>m; 
	string s;
	cin >>s; 
	if(n == m){
		cout <<0;
		return 0;
	}
	int c[n+1];
	for(int i = 1; i <= n; i++){
		cin >>c[i];
	}
	int p[n+1];
	for(int i = 1; i <= n; i++){
		p[i] = i;
	} 
	int ans = 0;
	do{
		int cnt = 0,cnt_s = 0;
		for(int i = 1; i <= n; i++){
			int cdd = p[i],dif = s[i-1]-'0';
			if(cnt >= c[cdd]){
				cnt++;
				continue;
			}
			if(!dif){
				cnt++;
			}else{
				cnt_s++;
			}
		} 
		if(cnt_s >= m){
			ans++;
			ans %= 998244353;
		}
	}while(next_permutation(p+1,p+n+1));
	cout <<ans;
	return 0;
} 
 
