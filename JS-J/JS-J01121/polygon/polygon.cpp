#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],num;
int c(int x)
{
	int p=1;
	for (int i=n;i>n-x;i--)
	{
		p*=i;
		p%=mod;
	}
	for (int i=2;i<=x;i++)
	{
		p/=i;
	}
	return p;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if (a[n]==1)
	{
		for (int i=3;i<=n;i++)
		{
			num+=c(i);
			num%=mod;
		}
		printf("%lld",num%mod);
		return 0;
	}
	if (n==4)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
					{
						num++;
					}
				}
			}
		}
		if (a[1]+a[2]+a[3]+a[4]>2*a[4]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==5)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
					{
						num++;
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					for (int o=k+1;o<=n;o++)
					{
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))
						{
							num++;
						}
					}
				}
			}
		}
		if (a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==6)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
					{
						num++;
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					for (int o=k+1;o<=n;o++)
					{
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))
						{
							num++;
						}
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					for (int o=k+1;o<=n;o++)
					{
						for (int p=o+1;p<=n;p++)
						{
							if (a[i]+a[j]+a[k]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[p],a[o])))))
							{
								num++;
							}
						}
					}
				}
			}
		}
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==7)
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							if (a[i]+a[j]+a[k]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[p],a[o]))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],a[o])))))) num++;
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==8)
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							if (a[i]+a[j]+a[k]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[p],a[o]))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],a[o])))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],a[o]))))))) num++;
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*a[8]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==9)
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							if (a[i]+a[j]+a[k]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[p],a[o]))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],a[o])))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],a[o]))))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									for (int ii=q+1;ii<=n;ii++)
										if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]+a[ii]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],max(a[ii],a[o])))))))) num++;
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*a[9]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	if (n==10)
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						if (a[i]+a[j]+a[k]+a[o]>2*max(a[i],max(a[j],max(a[k],a[o]))))num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							if (a[i]+a[j]+a[k]+a[o]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[p],a[o]))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],a[o])))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],a[o]))))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									for (int ii=q+1;ii<=n;ii++)
										if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]+a[ii]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],max(a[ii],a[o])))))))) num++;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				for (int k=j+1;k<=n;k++)
					for (int o=k+1;o<=n;o++)
						for (int p=o+1;p<=n;p++)
							for (int l=p+1;l<=n;l++)
								for (int q=l+1;q<=n;q++)
									for (int ii=q+1;ii<=n;ii++)
										for (int jj=i+1;jj<=n;jj++)
											if (a[i]+a[j]+a[k]+a[o]+a[p]+a[l]+a[q]+a[jj]+a[ii]>2*max(a[i],max(a[j],max(a[k],max(a[p],max(a[l],max(a[q],max(a[ii],max(a[jj],a[o]))))))))) num++;
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*a[10]) num++;
		printf("%lld",num%mod);
		return 0;
	}
	
}
