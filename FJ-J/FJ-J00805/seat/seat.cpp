#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for (int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int x=a[1],num=0;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]>=x)
		{
			num++;
		}
	}
	if(num%(2*n)==0)
	{
		cout<<num/n<<" "<<1;
	}
	else if(num%(2*n)<=n&&num%(2*n)!=0)
	{
		cout<<(num/(2*n))*2+1<<" "<<num%(2*n);
	}
	else
	{
		cout<<num/n+1<<" "<<n-num%n+1;
	}
	return 0;
}
