#include<bits/stdc++.h>
using namespace std;
#define N 105
long long n,m,Seats,cnt,x=1;
long long a[N];
long long b[N][N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	Seats=n*m;
	for(int i=1;i<=Seats;i++)
	{
		cin>>a[i];
	}
	cnt=a[1];
	sort(a,a+Seats);
	for(int k=Seats;k>=1;k--)
	{
		if(a[k]==cnt&&cnt==a[1])
		{
			cout<<k+(Seats-1)<<" "<<"1";
		}
		else if(a[k]==cnt&&cnt!=a[1])
		{
			cout<<k+1<<" "<<"1";
		}
	}
	return 0;
}
