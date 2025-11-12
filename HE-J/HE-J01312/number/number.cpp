#include<bits/stdc++.h>
using namespace std;
long long cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a;
	int b=0;
	long long c[1000001];
	for(int i=0;i<sizeof(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a=s[i]-'0';
			b++;
		}
		for(int i=b-1;i<b;i++)
		{
			c[i]=a;
		}
	}
	sort(c,c+b,cmp);
	for(int i=0;i<b;i++)
	{
		cout<<c[i];
	}
	return 0;
} 
