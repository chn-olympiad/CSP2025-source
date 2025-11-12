#include<bits/stdc++.h>
using namespace std;
int a[110];
int a_1=0;
int n,m;
void data()
{
	int b[110]={0};
	for(int i=1;i<=n*m;i++)
	{
		b[a[i]]++;
	}
	for(int i=100,j=1;i>=1;i--)
	{
		if(b[i])
		{
			a[j]=i;
			j++;
		}
	}
}
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		a_1=a[1];
	}
	data();
	int c=1,r=1,i=1;
	while(c<=m&&r<=n)
	{
		if(a_1==a[i])
		{
			cout<<c<<" "<<r;
			return 0;
		}
		i++;
		if(r==n&&c%2==1)
		{
			c++;
		} 
		else if(r<=n&&c%2==1)
		{
			r++;
		}
		if(r==1&&c%2==0)
		{
			c++;
		}
		else if(r>=1&&c%2==0)
		{
			r--;
		}
	}
	return 0;
}
