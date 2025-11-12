#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int main()
{
	long long n=0,l,i;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000010);
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++n]=s[i]-48;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(i=1;i<=n;i++)
	cout<<a[i];
	return 0;
} 
