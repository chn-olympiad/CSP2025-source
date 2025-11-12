#include <bits/stdc++.h>
using namespace std;
//#define int long long

vector <int>  ans;
string s;

bool cmp(int x, int y){
	return x > y;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	// 输入
	cin >> s;
	// 存储
	for(int i = 0; i < s.size();i ++){
		if ('0' <= s[i] && s[i] <= '9'){
			ans.push_back(s[i] -'0');
		}
	}
	// 排序
	sort(ans.begin(), ans.end(), cmp);
	// 处理
	// 输出
	int len = ans.size();
	for(int i = 0; i < len; i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}