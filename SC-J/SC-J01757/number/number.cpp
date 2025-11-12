#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int sze=s.size();
	int n=0;
	for(int i = 0;i<sze;i++){
		if('0'<=s[i]&&s[i]<='9') a[++n]=s[i];
	}
	sort(a+1,a+n+1);
	for(int i = n;i>=1;i--) cout << a[i];
	return 0;
}