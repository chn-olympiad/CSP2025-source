#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 50;
string s;
ll tong[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("number.in", "r", stdin);freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++) if(isdigit(s[i])) tong[s[i] - '0'] ++;
	for(int i = 9;i >= 0;i --) while(tong[i]) {cout << i;tong[i] --;}
	return 0;
}
