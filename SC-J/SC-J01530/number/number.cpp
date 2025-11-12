#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
char a[1000005];
ll s[1000005], cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> a;
	ll len = strlen(a);
	for(int i = 0; i < len; i ++){
		if(isdigit(a[i])){
			s[++ cnt] = (ll)(a[i] - '0');
		}
	}
	sort(s + 1, s + cnt + 1, greater<int>());
	for(int i = 1; i <= cnt; i ++){
		cout << s[i];
	}
	return 0;
}