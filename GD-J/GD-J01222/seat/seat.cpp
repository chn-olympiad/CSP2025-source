#include<bits/stdc++.h>
using namespace std;
int a,b;
int arr[50000],vis[50000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s,m;
	cin >> a >> b;
	for(int i=1;i<=a*b;i++)
	{
		cin >> arr[i];
	}
	s=arr[1];
	sort(arr+1,arr+1+a*b);
	
	for(int i=a*b,j=1;i>=1;i--,j++)
	{
		vis[j]=arr[i];
	}
	for(int i=1;i<=a*b;i++)
	{
		if(vis[i]==s)
		{
			m=i;
			break;
		}
	}
	int n=0,f=0;
	for(int i=1;i<=b;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=a;j++)
			{
				n++;
				if(n==m)
				{
					cout << i << ' ' << j;
					f=1;
					break;
				}
			}
		}
		else
		{
			for(int j=a;j>=1;j--)
			{
				n++;
				if(n==m)
				{
					cout << i << ' ' << j;
					f=1;
					break;
				}
			}
		}
		if(f==1) break;
	}
	return 0;
}
