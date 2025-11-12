#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
string s;
int a[1000005],n;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if('0'<=s[i] && s[i]<='9') a[++n]=s[i]-'0';
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout << a[i];
	return 0;
}
