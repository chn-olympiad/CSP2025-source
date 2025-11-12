//Author: mairuisheng
//#pragma GCC optimize(3)
#include<iostream>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=1e4+1;
int n,q;
string s[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	string t,t2;
	int i,cnt;
	for(i=1;i<=n;++i)cin>>s[i]>>s2[i];
	while(q--)
	{
		cin>>t>>t2;
		if(n>10000)puts("0");
		else
		{
			cnt=0;
			for(i=1;i<=n;++i)
			{
				if(s[i]==t&&s2[i]==t2)++cnt;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}
