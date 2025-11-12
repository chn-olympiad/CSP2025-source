#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> a;
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a.push_back(s[i] - '0');
			cnt++;
		}
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < cnt; i++){
		printf("%lld", a[i]);
	}
	printf("\n");
	return 0;
}