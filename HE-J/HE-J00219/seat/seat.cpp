#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int q,int w)
{
	return q>w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,id,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==id)
		{
			p=ceil((double)i/n);
			cout<<p<<" ";
			if(p%2==1)
			{
				if(i%n==0)
				cout<<n;
				else
				cout<<i%n;
			}
			else
			{
				if(i%n==0)
				cout<<"1";
				else
				cout<<n-i%n+1;
			}
			return 0;
		}
	}
	return 0;
}
