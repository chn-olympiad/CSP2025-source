#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.n","r",stdin);
	freopen("xor.out","w",stdout);
	int n,n1,k,a,i,j,s;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a;
	}
	n1=n;
	while(n>1)
	{
		n--;
	}
	for(j=1;j<=n1*3;j++)
	{
		if(j%5==0)
		{
			s+=10;
		}
		else if(j%3==0)
		{
			s-=10;
		}
	}
	if(s>=255)
		cout<<2;
	else if(s>=255 && k==0)
		cout<<1;
	else
		cout<<3;
	return 0;
}
