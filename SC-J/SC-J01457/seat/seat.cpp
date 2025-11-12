#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long RR,summ=0;
	cin>>RR;
	for (int i=2;i<=n*m;i++)
	{
		long long a;
		cin>>a;
		if (a>RR) summ++;
	}
	summ++;
	long long djl=summ/n,djh;
	summ%=n;
	if (summ==0)
	{
		if (djl%2!=0)
		{
			djh=n;
		}
		else 
		{
			djh=1;
		}
	}
	else
	{
		djl+=1;
		if (djl%2!=0)
		{
			djh=summ;
		}
		else 
		{
			djh=n-summ+1;
		}
	}
	
	cout<<djl<<" "<<djh;
	return 0;
}