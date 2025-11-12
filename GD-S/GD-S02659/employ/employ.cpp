#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c[500];
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	bool pd = true;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '0'){
			pd = false;
		}
	}
	if(pd){
		cout << 0;
		return 0;
	} else {
		long long ans = 1;
		for(int i = 1; i < n; ++i){
			ans = (ans * i);
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
