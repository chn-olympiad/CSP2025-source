#include<iostream>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		sum=a[l];
		if(sum==k)
		{
				
			ans++;
			continue;
		}
		for(int r=l+1;r<=n;r++)
		{
			
			sum=(sum^a[r]);
			if(sum==k)
			{
				
				ans++;
				l=r;
				break;
				
			}
		}
	}
	cout<<ans;
	return 0;
}
