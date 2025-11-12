
#include<bits/stdc++.h>

using namespace std;
int a[10010];

int main()
{	
//25pts
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;

	cin>>n>>k;
	//cout<<"GET!";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	//	cout<<"GET!\n";
	}
	//cout<<"debug\n";
	int ans=0;
	if(k==1)
	{
		//cout<<"debug\n";
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
		
	}
	else//k==0
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			
		}
			
		cout<<ans;
		return 0;
	}
	
	return 0;
}
