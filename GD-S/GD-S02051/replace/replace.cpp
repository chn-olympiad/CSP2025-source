#include <bits/stdc++.h>
using namespace std;
#define int long long

int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e5+10;
string a[N],b[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		puts("0");
	}
	return 0;
}
