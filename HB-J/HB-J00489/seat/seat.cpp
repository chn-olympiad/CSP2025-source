#include<iostream>
#include<stdio.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])num++;
	}
	num++;
	int k=num/(n*2)*2;
	int s=num%(n*2);
	if(s<=n)
	{
		cout<<k+1<<" "<<s;
	}
	else
	{
		cout<<k+2<<" "<<n-(s-n)+1;
	}
	return 0;	
}
