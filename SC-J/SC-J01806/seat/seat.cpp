#include<bits/stdc++.h>
using namespace std;
int a[10005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int R=a[1],Rcnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			Rcnt=i;
			break;
		}
	}
	int x=Rcnt/n;
	int y=Rcnt%n;
	if(y!=0)
	{
		x++;
	}
	if(x%2!=0)
	{
		if(y==0)y=n;
		cout<<x<<" "<<y;
	}
	else 
	{
		if(y==0)y=n;
		cout<<x<<" "<<(n-y+1);
	}
	return 0;
}