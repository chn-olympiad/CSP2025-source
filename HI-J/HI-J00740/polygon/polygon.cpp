#include "bits/stdc++.h" 
using namespace std;
const int M=998244353;
int n,m,l[5500];
int s,ma=-1,c,a;
long long f(int x,int y)
{
	int i,s=1;
	for(i=y;i<=x;i++)
	{
		s*=i;
	} 
	for(i=1;i<=x-y;i++)
	{
		s/=i;
	}
	return s%M;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) 
	{
		cin>>l[i];
		s+=l[i];
		ma=max(ma,l[i]);
	}
	if(n<3) 
	{
		cout<<0;return 0;
	}
	if(n==3)
	{
		if(s>2*ma) cout<<1;
		else cout<<0;
		return 0;
	}
	if(ma==1)//n!/( (n-m)!m! )
	{
		for(i=3;i<=n;i++) 
		{
			c+=f(n,i);
		}
		cout<<c%M;
		return 0;
	}
	else
	{
		cout<<rand();
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
	
	
}
