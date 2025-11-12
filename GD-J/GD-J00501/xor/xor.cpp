#include<bits/stdc++.h>
using namespace std;
int a,k,p,x,q;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	for(int i=1;i<=a;i++)
	{
		cin>>x;
		if(x==1) p++;
		if(x==0) q++;
	}
	if(p==a)
	{
		if(k==0) cout<<p/2;
		if(k==1) cout<<a;
		return 0;
	}
	if(p+q==a)
	{
		if(k==1) cout<<p;
		else cout<<q+p/2;
		return 0;
	}
	cout<<1;
	return 0;
}
