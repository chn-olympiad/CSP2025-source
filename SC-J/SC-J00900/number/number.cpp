#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string s;
ll a[1000005], len, cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> s;
	len = s.size();
	
	for (int i = 0; i < len; i ++ ){
		if (s[i] >= '0' && s[i] <= '9'){
			cnt ++ ;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt);
	
	for (int i = cnt; i >= 1; i -- ){
		cout << a[i];
	}
	
	return 0;
}