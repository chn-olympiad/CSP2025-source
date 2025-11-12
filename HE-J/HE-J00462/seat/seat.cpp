#include<bits/stdc++.h>
using namespace std;
const int N=11,M=11;
int n,m,e=1,nn=1,mm=1;
int a[N][M];
int aa[N*M];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>aa[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(aa[1]>aa[i+1])
		{
			d=d-1;
		}
	}
	d=d+1;
	for(int i=1;i<=n*m;i++)
	{
		if(mm%2==1)
		{
			if((d==3||d%3==1)&&d==1)
			{
				cout<<mm<<" "<<nn-1;
				return 0;
			}
			if(nn<n)
			{
				d--;
				nn++;
				if(d==1)
				{
					cout<<mm<<" "<<nn;
					return 0;
				}
			}
			if(nn==n)
			{
				mm++;
				d--;
				if(d==1)
				{
					cout<<mm<<" "<<nn;
					return 0;
				}
				nn=n;
			}
		}
		if(mm%2==0)
		{
			if((d==3||d%3==1)&&d==1)
			{
				cout<<mm<<" "<<nn-1;
				return 0;
			}
			if(nn!=0)
			{
				d--;
				nn--;
				if(d==1)
				{
					cout<<mm<<" "<<nn;
					return 0;
				}
			}
			if(nn==1)
			{
				mm++;
				d--;
				if(d==1)
				{
					cout<<mm<<" "<<nn;
					return 0;
				}
				nn=n;
			}
		}
	}
	cout<<mm<<" "<<nn;
	return 0;
}
