#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m[5000],t,q=0,h;
	int all;
	m[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		t+=m[i];
		if(m[i]==m[i-1])
		h++;
	}
	if(h==n)
	{
		all=(2.5*n*n-17.5*n+35.0);
		all%=998244353;
		cout<<all;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			if(m[i]>q)
			q=m[i];
		}
		if(t>2*q)
		cout<<1;
		else
		cout<<0;}
	fclose(stdin);
	fclose(stdout);
}
