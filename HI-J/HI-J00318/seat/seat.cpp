#include<bits/stdc++.h>
using namespace std;
int a[101];
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	
	bool t=1;
	int n,m;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	int k=1;
	sort(a+1,a+num+1,f);
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>0;j--)
			{
				if(a[k]==r)
				{
					cout<<i<<" "<<j;
					t=0;
					break;
				}
				k++;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(a[k]==r)
				{
					cout<<i<<" "<<j;
					t=0;
					break;
				}
				k++;
			}
		}
		if(t==0)
		{
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
