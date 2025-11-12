#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[103];
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int a0=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			swap(a[j],a[j+1]);
		}
	}
	int wz;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a0)
		{
			wz=i;
			break;
		}
	}
	int k,t;
	if(wz%n)
	k=wz/n+1;
	else
	k=wz/n;
	if(k%2)
	{
		if(wz%n)
		t=wz%n;
		else
		t=wz%n+1;
	}
	else
	{
		if(wz%n)
		t=n-(wz%n)+1;
		else
		t=1;
	}
	cout<<k<<' '<<t;
	return 0;
}
