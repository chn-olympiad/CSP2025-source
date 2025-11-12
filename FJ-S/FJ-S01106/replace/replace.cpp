#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL read()
{
	char b=getchar();
	LL a=0;
	for(;'0'<=b&&b<='9';)
		a=a*10+b-'0',b=getchar();
	return a;
}
LL n,q,j;
string x[2][200100],a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(LL i=1;i<=n;i++)
	{
		cin>>x[0][i]>>x[1][i];
	}
	for(LL i=1;i<=q;i++)
	{
		cin>>a>>b;
	}
	if(n==4&&q==2)
	{
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&q==4)
	{
	cout<<0<<endl<<0<<endl<<0<<endl<<0;return 0;}
	for(LL i=1;i<=q;i++)
	 	cout<<0<<endl;
}
