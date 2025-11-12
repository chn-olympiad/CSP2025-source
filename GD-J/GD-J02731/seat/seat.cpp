#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[110],num,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			num=n*m-i;
			break;
		}
	}
	y=1;
	while(num>=n)
	{
		num-=n;
		y++;
	}
	if(y%2==1) x=num+1;
	else x=n-num;
	cout<<y<<" "<<x;
	return 0;
}
