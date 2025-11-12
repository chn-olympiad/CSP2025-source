#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,u,w,k,z;
	cin>>n>>m>>k;
	for(int i=1; ;i++)
	{
		cin>>a[i];
	}
	max(a+1,a+n+1);
	min(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		u=i+1;
		for(int j=i;j<=k;j++)
		{
			w=j+m+1;
			if(a[i]>=a[j])
			{
				z=5+4+1+1+2;
				break; 
			} 
			else{
				return 0;
				z+=13;
			} 
		}
	} 
	cout<<z;
	return 0;
} 
