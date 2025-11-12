#include <iostream>
#include <algorithm>
#include<cstdio>

using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
	   {
			b=i;
		}
	}
	int c,r,flag=0;
	if(b%n==0)//判断列数 
	{
		c = b/n;//最后一位或第一位 
		flag = 1; 
	}
	else{
	   c = b/n+1;
	}
	if(c%2==1)
	{
		if (flag==1)
		{
			r = n;
		 }
		 else{
		 	
		r = b%n+1;
		}
	}
	else
	{
		if(flag==1){
			r=1;
		}
		else{
		
		r = n-b%n+1;
	}
	}
	cout<<c<<" "<<r;
	return 0;
}

