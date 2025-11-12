#include<bits/stdc++.h>
using namespace std;
string a[1000010];
int ans=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1)
	{
		if(s[0]>='0'&&s[0]<='9')
		{
			cout<<s[0];
			return 0;
		}
	}
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[ans]=s[i];
			ans++;
		}
	}
	sort(a,a+ans);
	for(int i=ans;i>=1;i--)
	{
	    cout<<a[i];
	}
	return 0;
}
