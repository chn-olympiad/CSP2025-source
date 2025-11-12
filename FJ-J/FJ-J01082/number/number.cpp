#include<bits/stdc++.h>
using namespace std;
//long long read()
//{
//	long long n1,x1=0,f=1;
//	char c;
//	c=getchar();
//	while(c>'9'||c<'0')
//	{
//		if(c=='-')
//		{
//			f=-1;
//		}
//		c=getchar();
//	}
//	while(c<='9'&&c>='0')
//	{
//		x1*=10;
//		x1+=c-48;
//		c=getchar();
//	}
//    return x1*f;
//}
char c[1145140];
long long sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int z=0;z<s.size();z++)
	{
		if(s[z]<='9'&&s[z]>='0')
		{
			c[sum]=s[z];
			sum++;
		}
	}
	sort(c,c+sum);
	for(int z=sum-1;z>=0;z--)
	{
		cout<<c[z];
	}
	return 0;
}
