#include<bits/stdc++.h>
using namespace std;
int p[110],q[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,i,j,t;
	cin>>a>>b;
	t=a*b;
	for(i=1;i<=t;i++)
	{
		cin>>p[i];
		q[i]=p[i];
	}
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(q[j]<q[j+1]) t=q[j],q[j]=q[j+1],q[j+1]=t;
		}
	}
	for(i=1;i<=a*b;i++)
	{
		if(q[i]==p[1]) 
		{
			if(i%a==0)
			{
				if((i/a)%2==1) cout<<i/a<<" "<<a;
				else cout<<i/a<<" "<<1;
			}
			else if((i/a+1)%2==1) cout<<i/a+1<<" "<<i-(i/a)*a;
			else cout<<i/a+1<<" "<<i-i/a;
		}
	}
	return 0;
}
