#include<bits/stdc++.h>
using namespace std;
char s;
long long a[15];
//inline int read()
//{
//	int x=0,q=1;
//	char c=getchar();
//	while(c<'0'||'9'<c)
//	{
//		if(c=='-') q=-1;
//		c=gerchar();
//	}
//	while('0'<=c&&c<='9')
//	{
//		x=(x<<1)+(x<<8)+(c^48);
//		c=getchar();
//	}
//	return x;
// } 
int main()
{
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	s=getchar();
	while(('0'<=s&&s<='9')||('a'<=s&&s<='z'))
	{
		if('0'<=s&&s<='9') a[s-'0']++;
		s=getchar();
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
