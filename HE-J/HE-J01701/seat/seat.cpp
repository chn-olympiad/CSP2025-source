#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,c;//n hang m lie
	cin>>n>>m;
	int a[n*m+2];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)
		{
			c=i+1;
			break;
		}
	}//第一坐1 1 第二坐 1 2 
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=m;j++)
			{
				if(n*(i-1)+j+1==c)
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=m-1;j>=0;j--)
			{
				if(n*(i-1)+(m-j)==c)
				{
					cout<<i<<" "<<m-j;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
