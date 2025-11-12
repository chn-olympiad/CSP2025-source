#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int a[N];
bool cmp(ll a, ll b){
	if(a > b) return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll cnt = 0;
	for(ll i= 0;i <= s.size()-1;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt] = s[i]-48;
			cnt++;
		} 
	}
	sort(a,a+cnt,cmp);
	for(ll i =0;i < cnt;i++) cout << a[i];
	return 0;
}

