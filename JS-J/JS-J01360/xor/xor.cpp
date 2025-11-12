#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool fa=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			fa=1;
			break;
		}
	}
	if(!fa&&k==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	if(!fa&&k==1)
	{
		cout<<n<<endl;
		return 0;
	}	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		int c=a[j];
		while(c!=k&&j<=n) 
		{
			j++;
			c^=a[j];
		}
		ans++;
		//cout<<i<<" "<<j<<" "<<ans<<endl;
		i=j;
		
	}
	cout<<ans<<endl;
	return 0;
}
