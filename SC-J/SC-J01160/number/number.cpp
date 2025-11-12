#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ls(u) u << 1
#define rs(u) u << 1 | 1
using namespace std;
const int maxn = 1e6 + 55, mod = 998244353;
const double pi = acos(-1);
int T;
int n, m;
string a;
int cnt[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for(int i = 0;i < (int)a.size();i ++){
		if(a[i] <= '9' && a[i] >= '0'){
			cnt[a[i] - '0'] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		for(int j = 1;j <= cnt[i];j ++){
			cout << i;
		}
	}
	return 0;
}