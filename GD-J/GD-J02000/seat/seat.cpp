#include<iostream>
#include<algorithm>

using namespace std;

int n,m;

int a[105];

int pts,plc;

void input()
{
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	pts=a[1];
}

void finding()
{
	sort(a+1,a+n*m+1);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pts)
		{
			plc=n*m-i+1;
			
			break;
		}
	}
}

void solve()
{
	cout<<(plc-1)/n+1<<" ";
	
	if((plc-1)%(2*n)<n)
	{
		cout<<(plc-1)%(2*n)+1;
	}
	else
	{
		cout<<2*n-(plc-1)%(2*n);
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	input();
	
	finding();
	
	solve();
}
