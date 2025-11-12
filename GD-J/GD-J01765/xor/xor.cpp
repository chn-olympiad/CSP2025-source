#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005],ans=0,sum[1005][1005];
bool vis[50005],flag0=1,flag1=1;
int main()
{
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0){
			flag0=0;
		}
		if(a[i]!=1&&a[i]!=0){
			flag1=0;
		}
	}
	if(flag0)
	{
		cout<<n;
		return 0;
	}
	if(flag1)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
			cout<<ans;
			return 0;
		}
		if(k==0)
		{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			for(int i=1;i<=n;i++){
				if(a[i]&&a[i+1])
				{
					ans++;
					i++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	

	
	for(int i=1;i<=n;i++){
		sum[i][i]=a[i];
	}
	for(int i=1;i<n;i++)
	    for(int j=i+1;j<=n;j++)
	    {
	    	sum[i][j]=sum[i][j-1]^sum[j][j];
		}
	for(int w=0;w<n;w++)
	{
		for(int i=1;i<=n-w;i++)
		{
			bool flag3=1;
			for(int mq=i;mq<=i+w;mq++)
			    if(vis[mq])
			        flag3=0;
			if(sum[i][i+w]==k&&flag3==1){
				ans++;
				for(int mq=i;mq<=i+w;mq++)
			        vis[mq]=1;
			}
		}
	}
	cout<<ans;
	
	 
	
	
	
	
	return 0;
}
