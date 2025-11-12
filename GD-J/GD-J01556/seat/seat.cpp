#include<bits/stdc++.h>
using namespace std;
int n,m,mb,a[105]; 
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)mb=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int l=0,r=n*m+1,mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(a[mid]==mb)
		{
			mb=mid;
			break;
		}
		if(a[mid]>mb)l=mid;
		else r=mid;
	}
	for(int i=1,jsq=1;i<=m;i++)
	{
		if(i%2==1)
		for(int j=1;j<=n;j++)
		{
			if(jsq==mb)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			jsq++;
		}
		else
		for(int j=n;j>=1;j--)
		{
			if(jsq==mb)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			jsq++;
		}
	}
	return 0;
}
