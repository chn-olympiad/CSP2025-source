#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l1=s.size();
	for(int i=0;i<l1;i++)
	{
		if(s[i]-'0'<=9&&s[i]-'0'>=0)
		{
			a[s[i]-'0']++;
		}
	}
	//for(int i=0;i<=9;i++) cout<<i<<":"<<a[i]<<endl;
	for(int j=9;j>=0;j--)
	{
		for(;;)
		{
			if(a[j]!=0)
			{
				cout<<j;
				a[j]-=1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
