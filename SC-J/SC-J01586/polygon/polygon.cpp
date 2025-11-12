#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 998244353;
int n,cnt[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	else if(n == 3){
		int a,b,c;
		cin >> a >> b >> c;
		int maxx = max(max(a,b),c);
		if(a+b+c > 2 * maxx) cout << 1;
		else cout << 0;
		return 0;
	}
	return 0;
}