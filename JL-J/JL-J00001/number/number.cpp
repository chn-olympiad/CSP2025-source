#include<bits/stdc++.h>
using namespace std;
string s="";
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s+='\n';
	int l=0;
	for(int i=0;s[i]!='\n';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[l]=int(s[i]-'0');
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
