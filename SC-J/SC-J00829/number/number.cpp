#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int fnum=0;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[i+1]=s[i]-'0';
		}
		else  fnum++;
	}
	sort(a+1,a+s.size()+1);
	for(int i=s.size();i>=fnum+1;i--)
	{
		cout<<a[i];
	}
	
	return 0;
} 