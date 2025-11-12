#include<bits/stdc++.h>
using namespace std;
int n,m,a[555],r,l,h;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			l=(i-1)/n+1;
			h=(i-1)%n+1;
			cout<<l<<' ';
			if(l%2==0)
			h=n+1-h;
			cout<<h;
			break;
		}
	}
	return 0;
} 
