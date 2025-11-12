#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5001, Mod=998244353;
int a[N], ans;
void dfs(int deep, int n, int now, int cnt)
{
//	cout<<deep<<" "<<n<<" "<<now<<" "<<cnt<<endl;
	if(deep==n)
	{
		if(cnt>a[now])
			ans=(ans+1)%Mod;
		return ;
	}
	for(int i=1;now+i<=n;i++)
		dfs(deep+1, n, now+i, cnt+a[now]);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.ans", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	if(a[n]==1)
	{
		int ans=1, sum=3;
		for(int i=4;i<=n;i++)
		{
			ans=(ans*2+sum)%Mod;
			sum+=i-1;
		}
		cout<<ans;
		return 0;
	}
	if(n==3)
	{
		cout<<((a[1]+a[2]>a[3])?"1\n":"0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[i]+a[j]>a[k])
					ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					if(a[i]+a[j]+a[k]>a[l])
						ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						if(a[i]+a[j]+a[k]+a[l]>a[m])
							ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o])
								ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p])
									ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int q=p+1;q<=n;q++)
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q])
										ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int q=p+1;q<=n;q++)
									for(int r=q+1;r<=n;r++)
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r])
											ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int q=p+1;q<=n;q++)
									for(int r=q+1;r<=n;r++)
										for(int s=r+1;s<=n;s++)
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[s])
												ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int q=p+1;q<=n;q++)
									for(int r=q+1;r<=n;r++)
										for(int s=r+1;s<=n;s++)
											for(int t=s+1;t<=n;t++)
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[t])
													ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						for(int o=m+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int q=p+1;q<=n;q++)
									for(int r=q+1;r<=n;r++)
										for(int s=r+1;s<=n;s++)
											for(int t=s+1;t<=n;t++)
												for(int u=t+1;u<=n;u++)
													if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>a[u])
														ans++;
//	for(int i=3;i<=n;i++)
//		dfs(0, i, 0, 0);
	cout<<ans;
	return 0;
}

