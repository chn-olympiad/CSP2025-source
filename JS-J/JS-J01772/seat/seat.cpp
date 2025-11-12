#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	int x=0,y=0;
	int k=n*m;
	for (int i=1;i<=k;++i)
	{
		cin>>a[i];
		if (a[i]>a[1])
			sum+=1;
	}
	sum+=1;
	if (sum%n==0)
	{
		x=sum/n;
		y=n;
		cout<<x<<" "<<y<<endl;
		return 0;
	}
	x=(sum/n)+1;
	if (x%2==1)
		y=sum%n;
	else
		y=(n+1-sum%n);
	cout<<x<<" "<<y<<endl;
	return 0;
}
