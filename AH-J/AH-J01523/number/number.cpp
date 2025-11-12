#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j=0;
long long ans=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++j]=s[i]-'0';
		}
	}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
