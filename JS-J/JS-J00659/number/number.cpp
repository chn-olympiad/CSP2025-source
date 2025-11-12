#include <bits/stdc++.h>
using namespace std;


int a[1000005]={0};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long cnt=0;
	for(long unsigned int i=0;i<s.length();i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			cnt++;
			a[cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(long long i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
