#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=1e5+5,mod=998244353,inf=0x3f3f3f3f;
string s,t="";
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>s;
	for(auto i:s)
		if('0'<=i&&i<='9')
			t+=i;
	sort(t.begin(),t.end(),greater<char>());
	cout<<t;
	return 0;
}

