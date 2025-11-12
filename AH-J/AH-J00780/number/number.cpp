#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long i,c=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			c++;
			a[c]=int(s[i])-48;
		}
	}
	sort(a+1,a+c+1);
	long long f=0;
	for(i=c;i>=1;i--)
	{
		if(a[i]!=0)
		{
			f=1;
			cout<<a[i];
		}
		if(a[i]==0&&f==1)
			cout<<a[i];
	}
}
