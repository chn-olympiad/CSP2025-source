#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN = 1e6+5;

string s;
int number[MAXN];
int cnt;
bool cmp(int a,int b) {
	return a>b;
}

signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len = s.size();
	for (int i=1;i<=len;i++) {
		if (s[i-1] >= '0' && s[i-1] <= '9') {
			number[++cnt] = s[i-1] - '0';
		}
	}
	sort(number+1,number+1+cnt,cmp);
	for (int i=1;i<=cnt;i++) cout<<number[i];
	return 0;
}