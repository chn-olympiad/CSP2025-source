#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[114514];
	int t[114514]={0};
	cin>>s;
	int m=1;
	for (int i=0;i<=100000;i++)
	{
		if (s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='0')
		{
			t[m]=s[i]-48;
			m++;
		}
	}
	sort(t,t+m+1);
	for (int i=m;i>=2;i--)
	{
		cout<<t[i];
	}
	return 0;
}