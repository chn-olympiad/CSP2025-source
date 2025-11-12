#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=1e5+10;

int n,t[N]; string s;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s; n=s.size(); s=" "+s;
	for(int i=1;i<=n;++i)
		if(s[i]>='0'&&s[i]<='9') ++t[s[i]-'0'];
	for(int i=9;i>=0;--i)
		while(t[i]) cout<<i,--t[i];
	return 0;
}