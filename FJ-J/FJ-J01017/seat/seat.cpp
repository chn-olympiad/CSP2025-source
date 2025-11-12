#include<iostream>
using namespace std;
int s[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],A,sum=0;
	int c=1,r=0;//列 行 
	bool top=1;
	cin>>n>>m>>A;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>a[i];
		if(a[i]>A)sum++;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum--;
			if(top)r++;//行 
			if(!top)r--;
			if((r>n && top) || (r<1 && !top))
			{
				c++;//列 
				if(!top)r=1;//行
				if(top)r=n;
				top= !top;
			}
			if(sum<=0)
			{
				break;
			}
		}
	}
	cout<<c<<' '<<r;//列 行 
	return 0;
}
//2 2 99 100 97 98
//3 1
//3 2
//8 3
