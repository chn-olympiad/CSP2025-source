#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5;
int a[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;cin>>s;
	for(int i=0;i<s.size();i++) if(isdigit(s[i])) a[s[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=a[i];j++) cout<<i;
	return 0;
}
