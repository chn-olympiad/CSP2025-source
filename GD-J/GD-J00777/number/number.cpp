#include<bits/stdc++.h>
//#define int long long
using namespace std;
char s;
string ans;
int q[120];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		q[s-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(q[i]--) ans+=i+'0';
	}
	cout<<ans;
	return 0;
} 
