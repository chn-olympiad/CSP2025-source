#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int d(int x,int y,int a)
{
	int f;
	if(f==a)
	{
		return x,y;
	}
	if(x%2==1)
	{
		d(x,y+1,xx); 
		f++;
	}
	if(x%2==0)
	{
		d(x,y-1,xx); 
		f++;
	}
	if(y==n)
	{
		d(x=1,y,xx);
		f++;
	}
	if(y==1)
	{
		d(x+1,y,xx);
		f++;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int a[105][105],stu[100000005];
	int m,r,n,p;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>stu[i];
		if(i==1) r=str[i];
	}
	sort(stu+1,stu+1+n);
	for(int i=1;i<=n*m;i++)
	{
		if(stu[i]==r)
		{
			p=i;
			break;
		}
	}
	int xx=stu[1];
	cout<<d(m,n,xx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}