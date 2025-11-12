#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5005];
int n;
const int mod=998244353;
int num=0;
void dfs(int x)
{
	if(x==n+1) return;
	if(x==3)
	{
		for(int i=1;i<=n-2;i++)
		{
			int ans=0,maxn=-1;
			for(int j=i+1;j<=n-1;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					ans=a[i]+a[j]+a[k];
					maxn=max(a[i],max(a[j],a[k]));
					if(ans>maxn*2){
						num++;
						num%=mod;
					}
				}
			}
		}
	}
	else if(x==4)
		{
		for(int i=1;i<=n-3;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-2;j++)
			{
				for(int k=1+j;k<=n-1;k++)
				{
					for(int l=1+k;l<=n;l++)
					{
						ans=a[i]+a[j]+a[k]+a[l];
						maxn=max(a[i],max(a[j],max(a[k],a[l])));
						if(ans>maxn*2) {
						num++;
						num%=mod;
						}
					}
				}
			}
		}
	}
	else if(x==5)
	{
		for(int i=1;i<=n-4;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-3;j++)
			{
				for(int k=1+j;k<=n-2;k++)
				{
					for(int l=1+k;l<=n-1;l++)
					{
						for(int r=l+1;r<=n;r++)
						{
						ans=a[i]+a[j]+a[k]+a[l]+a[r];
						maxn=max(a[i],max(a[j],max(a[k],max(a[l],a[r]))));
						if(ans>maxn*2) {
						num++;
						num%=mod;
						}
						}
					}
				}
			}
		}
	}
	else if(x==6)
	{
		for(int i=1;i<=n-5;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-4;j++)
			{
				for(int k=1+j;k<=n-3;k++)
				{
					for(int l=1+k;l<=n-2;l++)
					{
						for(int r=l+1;r<=n-1;r++)
						{
							for(int o=r+1;o<=n;o++)
							{
								ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o];
								maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],a[o])))));
								if(ans>maxn*2) {
								num++;
								num%=mod;
								}
							 } 
						}
					}
				}
			}
		}
	}
	else if(x==7)
	{
		for(int i=1;i<=n-6;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-5;j++)
			{
				for(int k=1+j;k<=n-4;k++)
				{
					for(int l=1+k;l<=n-3;l++)
					{
						for(int r=l+1;r<=n-2;r++)
						{
							for(int o=r+1;o<=n-1;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o]+a[p];
									maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],max(a[o],a[p]))))));
									if(ans>maxn*2) {
									num++;
									num%=mod;
									}
								}
							 } 
						}
					}
				}
			}
		}
	}
	else if(x==8)
	{
		for(int i=1;i<=n-7;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-6;j++)
			{
				for(int k=1+j;k<=n-5;k++)
				{
					for(int l=1+k;l<=n-4;l++)
					{
						for(int r=l+1;r<=n-3;r++)
						{
							for(int o=r+1;o<=n-2;o++)
							{
								for(int p=o+1;p<=n-1;p++)
								{
									for(int u=p+1;u<=n;u++)
									{	
										ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o]+a[p]+a[u];
										maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],max(a[o],max(a[p],a[u])))))));
										if(ans>maxn*2) {
										num++;
										num%=mod;
										}
									}
								}
							 } 
						}
					}
				}
			}
		}
	}
	else if(x==9)
	{
		for(int i=1;i<=n-8;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-7;j++)
			{
				for(int k=1+j;k<=n-6;k++)
				{
					for(int l=1+k;l<=n-5;l++)
					{
						for(int r=l+1;r<=n-4;r++)
						{
							for(int o=r+1;o<=n-3;o++)
							{
								for(int p=o+1;p<=n-2;p++)
								{
									for(int u=p+1;u<=n-1;u++)
									{	
										for(int t=u+1;t<=n;t++)
										{
											ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o]+a[p]+a[u]+a[t];
											maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],max(a[o],max(a[p],max(a[u],a[t]))))))));
											if(ans>maxn*2) {
											num++;
											num%=mod;
											}
										}
									}
								}
							 } 
						}
					}
				}
			}
		}
	}
	else if(x==10)
	{
		for(int i=1;i<=n-9;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-8;j++)
			{
				for(int k=1+j;k<=n-7;k++)
				{
					for(int l=1+k;l<=n-6;l++)
					{
						for(int r=l+1;r<=n-5;r++)
						{
							for(int o=r+1;o<=n-4;o++)
							{
								for(int p=o+1;p<=n-3;p++)
								{
									for(int u=p+1;u<=n-2;u++)
									{	
										for(int t=u+1;t<=n-1;t++)
										{
											for(int q=t+1;q<=n;q++)
											{
												ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o]+a[p]+a[u]+a[t]+a[q];
												maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],max(a[o],max(a[p],max(a[u],max(a[t],a[q])))))))));
												if(ans>maxn*2) {
												num++;
												num%=mod;
												}
											}
										}
									}
								}
							 } 
						}
					}
				}
			}
		}
	}
	else if(x==11) 
	{
		for(int i=1;i<=n-10;i++)
		{
			int ans=0,maxn=-1;
			for(int j=1+i;j<=n-9;j++)
			{
				for(int k=1+j;k<=n-8;k++)
				{
					for(int l=1+k;l<=n-7;l++)
					{
						for(int r=l+1;r<=n-6;r++)
						{
							for(int o=r+1;o<=n-5;o++)
							{
								for(int p=o+1;p<=n-4;p++)
								{
									for(int u=p+1;u<=n-3;u++)
									{	
										for(int t=u+1;t<=n-2;t++)
										{
											for(int q=t+1;q<=n-1;q++)
											{
												for(int v=q+1;v<=n;v++)
												{
													ans=a[i]+a[j]+a[k]+a[l]+a[r]+a[o]+a[p]+a[u]+a[t]+a[q]+a[v];
													maxn=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],max(a[o],max(a[p],max(a[u],max(a[t],max(a[q],a[v]))))))))));
													if(ans>maxn*2) {
													num++;
													num%=mod;
													}
												}
											}
										}
									}
								}
							 } 
						}
					}
				}
			}
		}
	}
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	bool fl=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>1) fl=1;
	}
	sort(a+1,a+1+n); 
	if(fl==0){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=3)
	{
		if(n<=2)
		{
			cout<<0;
			return 0;
		}
		bool f=1;
		if(a[1]+a[2]<=a[3]) f=0;
		if(a[1]+a[3]<=a[2]) f=0;
		if(a[2]+a[3]<=a[1]) f=0;
		if(f==0) {
			cout<<0;
			return 0;
		}
		else cout<<1;
		return 0;
	}
	dfs(3);
	cout<<num%mod;
	return 0;
}
