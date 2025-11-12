#include <bits/stdc++.h> 
using namespace std;
#define int long long
string s;
int n,t[15];
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s,n=s.size();
	for(int i = 0;i < n;i ++) if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	for(int i = 9;i >= 0;i --) for(int j = 1;j <= t[i];j ++) cout << i; 
	return 0;
}
