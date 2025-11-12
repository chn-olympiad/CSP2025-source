#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector <ll> v;
bool cmp(ll a, ll b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.length(); i++) if (s[i] >= '0' && s[i] <= '9') v.push_back(s[i] - '0');
	sort(v.begin(), v.end(), cmp);
	for (ll i = 0; i < v.size(); i++) cout << v[i];
	return 0;
} 
