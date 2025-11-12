#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	int len = s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}