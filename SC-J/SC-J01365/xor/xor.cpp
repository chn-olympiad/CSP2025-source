#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,res=0;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int head=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=head;j--)
		{
			res=res xor a[j];
			if(res==k)
			{
				head=i+1;
				ans++;
				//cout<<res<<" "<<i<<" "<<j<<"\n";
				break;	
			} 
		}
		res=0;
	}
	cout<<ans;
	return 0;
}