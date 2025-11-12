#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int k,a[1000010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int tp = s.length();
	for(int i = 0;i < tp;i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++k] = s[i] - '0';
		}
	}
	
	sort(a + 1,a + k + 1);
	for(int i = k;i >= 1;i --) cout << a[i];
	return 0;
}
/*
begin time 18:28
end time 21:58

rp++
*/
