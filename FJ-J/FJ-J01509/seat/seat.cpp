#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int a[105];
int Rj;
int y1=0;

bool cmp(int a,int b)
{
	return a>b;
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
	Rj=a[1];
	sort(a+1,a+(n*m)+1,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int wz;
	for(int i=1;i<=n*m;i++)
	{
		if(Rj==a[i])
		{
			wz=i;
			break;	
		}
	}
	int c=wz/n;
	int y=wz%n;
	if(y!=0)
	{
		c++;
	}
	if(c%2==0)
	{
		y1=n-y+1;
	}
	if(y==1)
	{
		if(c%2==1)
		{
			y1=1;
		}
		else
		{
			y1=n;
		}
	}
	
	cout<<c<<" "<<y1<<endl;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
