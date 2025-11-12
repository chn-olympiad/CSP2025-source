#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
string s,s1;
int32_t main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>'9')
			break;
		s1+=s[i];
	}
	for(int i=s1.size()-1;i>=0;i--)
		cout<<s1[i];
	return 0;
}
