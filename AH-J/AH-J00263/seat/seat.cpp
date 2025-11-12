#include<bits/stdc++.h>
using namespace std;
int a[105],rank;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,stn=0,stm=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int rank=1;
	for(int i=1;i<=n*m;i++)
	{
		if(x<a[i]) rank++;
	}
	if(rank<=n)
	{
		cout<<1<<' '<<rank<<endl;
	}
	else
	{
		while(rank>n)
		{
			rank-=n;
			stm++;
		}
		if(stm%2==0) stn=1+n-rank;
		else stn=rank;
		cout<<stm<<' '<<stn<<endl;
	}
	return 0;
}
