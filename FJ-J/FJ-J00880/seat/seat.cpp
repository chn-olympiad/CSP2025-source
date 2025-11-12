#include<bits/stdc++.h>
using namespace std;
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0,sum=0;
	cin>>n>>m;
	int a[100000];
	for(int i=1;i<=n*m;i++) 
	{	
		scanf("%d",&a[i]);//cin>>a[i];
		if(i==1) num=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num)
		{
			sum=i;
		}
	}
	int y=sum/n,x;
	if(sum%n!=0)
	{
		y++;
	}
	if(y%2==1)
	{
		x=sum%n;
		if(x==0) x=n;
	}
	else{
		x=n-sum%n;
		if(sum%n==0)
		{
			x=1;
		}
		else{
			x=n-sum%n+1;
		}	
	}
	cout<<y<<" "<<x;
	return 0;
}
