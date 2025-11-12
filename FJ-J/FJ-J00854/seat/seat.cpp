#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c,r,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[i]>a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			R=i;
			break;
		}
	}
	c=(ceil(R*1.0/m));
	if(c%2==0)
	{
		if(R%n==1)r=n;
		else if(R%n==0)r=1;
		else if(R%n!=1&&R%n!=0)r=(n-(R%n))+1;
	}
	else if(c%2==1)
	{
		if(R%n==0)r=n;
		else if(R%n!=0)r=R%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
