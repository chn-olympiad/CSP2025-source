#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int b[10355];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long o=m*n;
	for(int i=1;i<=o;i++)
	{
		cin>>b[i];
	}
	int fk=b[1];
	int C=o;
	sort(b+1,b+o+1);
	int ans=1;
	int cnt=1;
	int ahs=1;
	while(C--)
	{
		if(ans%n!=0)
		{
			ans=ans%n;	
		}
		else
		{
			ans=n;
		}
		if(cnt%2==1)
			{
				a[ans][cnt]=b[o-ahs+1];
				if(ans+1<=n)
				{
					ans++;
				}
				else
				{
					cnt++;	
				}
			}
			else
			{ 
				a[ans][cnt]=b[o-ahs+1];
				if(ans-1>=1)
				{
					ans--;
				}
				else
				{
					cnt++;
				}
			}
			ahs++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==fk)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
