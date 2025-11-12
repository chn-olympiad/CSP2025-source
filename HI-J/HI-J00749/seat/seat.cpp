#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,xh=0;
	int cnt=0;
	int sum=0;
	cin>>n>>m;
	sum=n*m;
	int a[110];
	cin>>a[sum];
	xh=a[1];
	for(int i=0;i<=sum;i++)
	{
		if(a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	for(int j=0;j<=sum;j++)
	{
		if(a[j]!=xh)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if(cnt>n)
	{
		int p=cnt%m;
		cout<<p<<" "<<cnt/n;
	 }
	 else
	 {
	 	cout<<"1"<<" "<<cnt/n;
	  } 
	fcolse(stdin);
	fcolse(stdout);
	return 0;
} 
