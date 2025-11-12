#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,s,k;
bool cmd(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i*m+j];
		}
	}
	s=a[0];
	sort(a,a+n*m,cmd);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==s)
		{
			k=i+1;
		}
	}
	int ans=0; 
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<m;j++)
			{
				ans++;
				if(ans==k)
				{
					cout<<i+1<<" "<<j+1<<"\n";
					return 0;
				}	
			}
		}
		else
		{
			for(int j=m-1;j>=0;j--)
			{
				ans++;
				if(ans==k)
				{
					cout<<i+1<<" "<<j+1<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
} 
