#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5005];
int mod=998224353;
int ssum(int x,int y)
{
	int mm=0;
	for(int i=x;i<=y;i++)
	{
		mm+=a[i];
	}
	return mm;
}
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(1+a,1+a+n);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(ssum(i,j)>a[j]*2)
			{
				cnt++;
			}
		}
	 } 
	cout<<(cnt+mod)%mod;
	return 0;
} 
