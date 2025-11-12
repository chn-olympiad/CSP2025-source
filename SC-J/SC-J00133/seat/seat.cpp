#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie();cin.tie();
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int aaa=a[1];
	sort(a+1,a+n*m+1);
	int l=1,r=n*m,mid;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(a[mid]==aaa)
		{
			int lie=m-(mid-1)/n;
			cout<<lie<<" ";
			if(lie%2==1)
			{
				cout<<n-(mid-1)%n;
			}
			else
			{
				cout<<(mid-1)%n+1;
			}
			return 0;
		}
		else if(a[mid]>aaa)r=mid-1;
		else l=mid+1;
	}
	return 0;
}