#include<iostream>
using namespace std;
int main()
{
	int n,m,k,c,p=0,u[10000],v[10000],w[10000000],a[10000000];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	cin>>c;
	for(int j=1;j<=(n+1)*k;j++)
	{
		cin>>a[j];
	}
	for(int i=1;i<=n;i++)
	{
		p+=w[i];
	}
	cout<<p;
	return 0;
}
