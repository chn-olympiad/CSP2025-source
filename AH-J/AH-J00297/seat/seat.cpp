#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],k;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	int l=1,r=n*m;
	sort(a+1,a+r+1,cmp);
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<=k) r=mid;
		else l=mid+1;
	}
	int num=(l-1)/n+1;
	cout<<num<<' ';
	if(num%2==1)
	{
		cout<<(l-1)%n+1;
		return 0;
	}
	else 
	{
		cout<<n-(l-1)%n;
		return 0;
	}
	return 0;
}
