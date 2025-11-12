#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
int l;
string s,ans;
bool cmp(char x,char y) {return x>y;}
signed main()
{
	FAST_IO;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++)
	{
		if('0'<=s[i]&&s[i]<='9') ans+=s[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans<<'\n';
	return 0;
}
