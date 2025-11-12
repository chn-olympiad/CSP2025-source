#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,inf=1e18,mod=1e9+7;
string s;
int a[20];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' and s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]--) cout<<i; 
	}
	cout<<"\n";
	return 0;
}
