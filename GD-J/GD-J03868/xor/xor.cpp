#include<iostream>
using namespace std;
int a[1145141],f[1145141],maxer[1145141];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i]; 
		if(a[i]==k) f[i]=maxer[i-1]+1;
		for(int j=i-1;j>=1;j--)
		{
			sum^=a[j];
			if(sum==k)
			{
				f[i]=max(f[i],maxer[j-1]+1);
				break;
			}
		}
		maxer[i]=max(maxer[i-1],f[i]);
	}
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
