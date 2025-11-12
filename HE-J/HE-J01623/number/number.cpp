#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s,a;
int n,m=0;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0') 
		{
			a+=s[i];
			m++;
		}
		else continue;
	}
	if(m==1) 
	{
		cout<<a[0]-'0';
		return 0;
	}
	else 
	{
		sort(a.begin(),a.end());
		for(int i=m-1;i>=0;i--)
		{
			cout<<a[i]-'0';
		}
	}
	return 0;
}
