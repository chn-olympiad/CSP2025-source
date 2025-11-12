#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int pn=n*m;
	for(int i=1;i<=pn;i++)
	{
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+pn+1,cmp);
	int l=0,h=0;
	for(int i=1;i<=pn;i++)
	{
		if(a[i]==q)
		{
			
			if(i%n==0)
			{
				l=i/n;
				if(l%2==0)h=1;
				else h=n;
			}
			else 
			{
				l=i/n+1;
				if(l%2==0)h=n-i%n+1;
				else h=i%n;
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
