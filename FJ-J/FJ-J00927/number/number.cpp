#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len,a1=1;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(int(s[i])>=48 && int(s[i])<=57)
		{
			a[a1]=int(s[i])-48;
			a1++;
		}
	}
	sort(a+1,a+a1+1);
	for(int i=a1;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
