#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int sum=0;
	int n,m;
	int a[101]={0};
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			sum++;
	}	
	if(sum%n!=0)
	{
		int i=ceil(sum*1.0/n);
		cout<<i<<" ";
		if(i%2==0)
			cout<<n-floor(sum*1.0/n)*n+1;
		else
			cout<<sum-floor(sum*1.0/n)*n+1;
	}
	else
	{
		int i=sum*1.0/n+1;
		cout<<i<<" ";
		if(i%2==0)
			cout<<n;
		else
			cout<<1;
	}
	return 0;
}
