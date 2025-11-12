#include <bits/stdc++.h>
using namespace std;
long long a[10],l;
string s;
bool k;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	for (int i=0;i<l;i++) {
		if (s[i]>='0'&&s[i]<='9') a[(s[i]-'0')]++;
	}
	for (int i=9;i>=0;i--) {
		if (i>0&&a[i]) k=true;
		while (a[i]) {
			a[i]--;
			cout<<i;
			if (i==0&&(!k)) break;
		}
	}
	return 0;
}

