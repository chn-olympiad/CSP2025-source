#include<bits/stdc++.h>
using namespace std;
int s[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[a[i]-'0']++;
		}
	}
	int n=9;
	string ans;
	while(n>=0)
	{
		if(s[n]>0)
		{
			ans+=n+'0';
			s[n]--;
		}
		else
		{
			n--;
		}
	}
	cout<<ans;
	return 0;
} 
