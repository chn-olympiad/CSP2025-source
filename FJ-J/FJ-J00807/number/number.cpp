#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int pos=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[pos]=s[i];
			a[pos]-=48;
			pos++;
		}
	}
	sort(a+1,a+pos+1);
	for(int i=pos;i>=2;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
