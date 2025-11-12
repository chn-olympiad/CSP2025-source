#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[150];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			cnt=i;
		}
	}
	if(cnt%n==0)
	{
		c=cnt/n;
	}
	else
	{
		c=cnt/n+1;
	}
	if(c%2==0)
	{
		r=n-cnt%n+1;
	}
	else if(cnt%n==0)
	{
		r=n;
	}
	else
	{
		r+=cnt%n;
	}
	cout<<c<<' '<<r;
	return 0;
} 
