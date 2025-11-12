#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006]={0},j=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if((int(s[i])>=65&&int(s[i])<=90)||(int(s[i])>=97&&int(s[i])<=122))
		{
			continue;
		}
		else{
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
