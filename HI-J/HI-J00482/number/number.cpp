#include<bits/stdc++.h>
using namespace std;
char num[10]={'1','2','3','4','5','6','7','8','9','0'}; 
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s,n,ans;
	long long m[1000]={};
	cin>>s;
	for (int i=0;i<=s.size();i++)
	{
		if (s[i]=='1' || s[i]=='2'|| s[i]=='3'|| 
		s[i]=='4'|| s[i]=='5'|| s[i]=='6'||
		 s[i]=='7'|| s[i]=='8'|| s[i]=='9'|| s[i]=='0') n+=s[i];
	}
	for (int i=0;i<=n.size();i++)
	{
		m[i]=int(n[i]);
	}
	sort(m,m+s.size(),greater<long long>());
	for (int i=0;i<=n.length();i++)
	{
		ans+= m[i];
	}
	cout<<ans;
	return 0;
}
