#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int t[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	I AK CSP
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i]>0)
		{
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}