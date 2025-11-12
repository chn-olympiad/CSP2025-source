#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p,s,ansn=1,ansm=1,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	p=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p) s=i;
	}
	for(int i=1;i<s;i++)
	{
		if(ansn%2==1)
		{
			if(ansm==m) ansn++;
			else ansm++;
		}
		else
		{
			if(ansm==1) ansn++;
			else ansm--;
		}
	}
	cout<<ansn<<" "<<ansm;
	return 0;
} 
//9:39
