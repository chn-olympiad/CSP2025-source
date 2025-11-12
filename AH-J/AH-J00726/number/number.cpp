#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[15]={0};
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[(int)s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			a[i]--;
		}
	}
}
