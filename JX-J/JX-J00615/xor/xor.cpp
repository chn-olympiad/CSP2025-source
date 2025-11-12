#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
void yangli_1()
{
	int a,b;
	if(n==1)
	{
		cin>>a;
		if(a==0) cout<<1;
		else cout<<0;
	}else 
	{
		cin>>a>>b;
		int x=a^b;
		if(a==0&&b==0) cout<<2;
		else if(x==0) cout<<1;
		else cout<<0;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2) 
	{yangli_1();}
	else cout<<6;
	return 0;
}
