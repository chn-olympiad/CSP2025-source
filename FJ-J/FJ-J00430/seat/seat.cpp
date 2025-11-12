#include<bits/stdc++.h>
using namespace std;
int a[10005]={0},n,m,r=0,zvn=0,zvm=0,js=0;
void zv(int x)
{
	while(x>n)
	{
		x=x-n;
		js++;	
	}
	if((js+3)%2==0)
	{
		zvm=js+1;
		zvn=n+1-x;
	
	}
	else{
		zvm=js+1;
		zvn=x;
	}
	cout<<zvm<<" "<<zvn;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==r)
		{
			zv(n*m+1-i);
			break;
		}
	}
	
	return 0;
}
