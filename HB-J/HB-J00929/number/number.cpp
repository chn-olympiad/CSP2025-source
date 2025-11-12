#include <bits/stdc++.h>
using namespace std;
char s[500005];
long long a[1000005],b=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='1' && s[i]<='9')
		{
			a[i]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+strlen(s),cmp);
	for(int i=0;i<b;i++)
	{
		cout<<a[i];
	}
	return 0;
}	
