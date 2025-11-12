#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

string s;
long long ans,a[maxn],cnt,num[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	for(int i=1; i<=cnt; ++i) {
		num[a[i]]++;
	}
	for(int i=10; i>=0; --i) if(num[i]) for(int j=1; j<=num[i]; ++j)cout<<i;
	return 0;
}