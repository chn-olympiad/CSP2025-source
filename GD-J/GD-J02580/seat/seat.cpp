#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ar[100010]={};
	long long k=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>ar[i];
		if(i==1)
		{
	    	k=ar[i];
		}
	}
	sort(ar+1,ar+n*m+1,cmp);
	long long left=1,right=n*m;
	long long mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(ar[mid]>k)
		left=mid+1;
		else if(ar[mid]<k)
		right=mid-1;
		else
		break;
	}
	for(int i=1;i<=m;i++)
	{
		if(mid<=i*n)
		{
			if(i%2==1)
			{
				cout<<i<<" ";
				if(mid%n==0)
				cout<<n;
				else
				cout<<mid%n;
				return 0;
			}
			else
			{
				cout<<i<<" ";
				if(mid%n==0)
				cout<<1;
				else
				cout<<n-mid%n+1;
				return 0;
			}
		}
	}
	return 0;
} 
