#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 1;
string s;
int c[510];
bool check (string s) {
	int len = s.size();
	for(int i = 1; i <= len ; i ++ ) {
		if(s[i] != 1) return 0;
	}
	return 1;
}
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n ;i ++ ) cin >> c[i];
	if(check(s)) {
		for(int i = 1; i <= n;i ++) {
			ans *= i;
			ans%=998244353;
		}
		cout << ans << endl;
		return 0;
	}
	if(m==1){
		//1.找到最开始的那个1
		//2.统计比最开始的1大的c
		//3.输出
		int wei = 0;
		for(int i = 0; i < n ; i ++ ){
			if(s[i] == 1) {
				wei = i;
				break;
			}
		}
		ans = 0;
		
		wei++;
		for(int i =1; i <= n ;i ++ ) {
			if(c[i] >= wei)ans ++;
		}
		cout << ans << endl; 
	}
	return 0;
}
