#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flagc=1,flaga=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) flagc=0;
		if(a[i]==0) flaga=0;
	}
	if(!flagc){
		if(!flaga){
			cout<<n*(n+1)/2;
		}else{
			if(k==1){
				int ans=0;
				for(int i=1;i<n;i++)
				{
					if(a[i]!=a[i+1]) ans++;
				}
				for(int i=1;i<=n;i++)
				{
					for(int j=n;j>=i;j--)
					{
						int sum=0;
						for(int l=i;l<=j;l++)
						{
							sum+=a[i];
						}
						if(sum%(j-i+1)==0) ans++;
					}
				}
				cout<<ans<<endl;
			}else{
				int ans=0;
				for(int i=1;i<n;i++)
				{
					if(a[i]==a[i+1]) ans++;
				}
				for(int i=1;i<=n;i++)
				{
					for(int j=n;j>=i;j--)
					{
						int sum=0;
						for(int l=i;l<=j;l++)
						{
							if(a[i]==0) sum++;
						}
						if((j-i+1)/sum==2) ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
	}else{
		int ans=0;
		for(int i=1;i<n;i++)
		{
			if((a[i]^a[i+1])==k){
				ans+=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=i;j--)
			{
				int sum=a[i];
				for(int l=i+1;l<=j;l++)
				{
				sum=sum^a[l];
				}
				if(sum==k) ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 