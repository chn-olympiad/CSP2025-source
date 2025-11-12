#include<bits/stdc++.h>
#include<string>
using namespace std;
short s[10][10],t[100];
bool cmp(int a,int b)
{
	return a>b;
}
short n,m,k,a;
int main()
{
	freopen("seat.in","r",cin);
	freopen("seat.out","w",cout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>t[i];
	a=t[0];
	sort(t,t+n*m,cmp);
	for(int i=0;i<m;i++)
	{
		if(i%2)
		{
			for(int j=0;j<n;j++)
			{
				if(t[k++]=a)
				{
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				if(t[k++]=a)
				{
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}
		}
	}
}
