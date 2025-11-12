#include<bits/stdc++.h>

using namespace std;

int n,m;
int a;
int x;
int rk;
int c,r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<(n*m);i++)
	{
		cin>>x;
		if(x>a)
		{
			rk++;
		}
	}
	c=(rk/n)+1;
	if(c%2)
	{
		r=(rk%n)+1;
	}
	else
	{
		r=n-(rk%n);
	}
	cout<<c<<" "<<r;
}
