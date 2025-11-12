#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.length()+5],j=1;
	memset(a,0,sizeof(a));
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--)
	{
		if(a[i]<=9)
			cout<<a[i];
	}
	return 0;
}
