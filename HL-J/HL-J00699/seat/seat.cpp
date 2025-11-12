#include <bits/stdc++.h>
using namespace std;
int m,n,a[1005],r,gg,hang=0,lei=0,op;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>a[1];
	r=a[1];
	gg=m*n;
	for(int i=2;i<=m*n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+gg+1);
	for(int i=1;i<=n;i++)
	{
		lei++;
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				op++;
				hang++;
				if(a[op]==r)
				{
					cout<<hang<<" "<<lei;
				}
		    }
		}
		else if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				op++;
				hang--;
				if(a[op]==r)
				{
					cout<<lei<<" "<<hang;
				}
		    }
		}
	}
}