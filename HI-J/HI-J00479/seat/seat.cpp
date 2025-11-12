#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int s,num=0;
	s=a[0];
	sort(a-1,a+n*m);
	for(int i=n*m-1;i>=0;i--)
	{
		num++;
		if(a[i]==s)
		{
			break;
		}
	}
	int c=1,r;
	while(num-n>0)
	{
		num-=n;
		c++;
	}
	if(c%2==1)
	{
		r=num;
	}
	else
	{
		r=m-num+1;
	} 
	cout<<c<<' '<<r;
	return 0;
}
