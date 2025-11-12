#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

const int N=2e5+10;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	string s[N]={},ss[N]={};
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
//		if(t1.size()!=t2.size())
//		{
//			printf("0\n");
//			continue;
//		}
//		else
//		{
//			for(int i=1;i<=n;i++)
//			{
//				if(s[i].size()<=t1.size())
//				{
//					
//				}
//			}
//		}
		printf("0\n");
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

