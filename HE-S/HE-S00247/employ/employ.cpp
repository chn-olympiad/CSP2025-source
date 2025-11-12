#include<bits/std++.h>
using namesapce std;
char a[10001];
int b[10001],c[10001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=0,m=0,num=0;
	cin>>n>>m;
	int len=strlen(a);
	cin>>a;
	for(int i=1;i<=n;++i)
	{
		cin>>b[i];
	}
	for(int i=1;i<=len;++i)
	{
		c[i]=a[i-1];
	}
	cout<<num%998244353;
	return 0;
}
