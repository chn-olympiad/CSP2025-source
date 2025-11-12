#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[1000],b[1000],c[1000];
int look(int t,int w)
{
	for(int i=t;i<=w;i++)
	{
		c[i]=b[i];
	}
	sort(c+t,c+w);
	int sum=c[w];
	//cout<<c[w]-c[t]<<' '<<c[w]*2<<endl;
	if((c[w]-c[t])>=sum*2)
	{
		return 1;
		//cout<<t<<w;
	}
	else
	{
		return 0;
	}
}
int main()
{
	
	cin>>n;
	cin>>a[0];
	for(int i=1;i<n;i++)
	{
		cin>>s;
		a[i]=a[i-1]+s;
		b[i]=s;
	}
	long long sum;
	for(int i=0;i<n-3;i++)
	{
		for(int j=2;j<n;j++)
		{
			sum+=look(i,j);
		}
	}
	cout<<sum%998244353;
	return 0;
}
