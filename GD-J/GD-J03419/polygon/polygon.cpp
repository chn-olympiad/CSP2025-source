#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n>=3)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					if (a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2)
					{
						ans++;
						ans%=998244353;
					}
				}
			}
		}
	}
	if (n>=4)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						if (a[i]+a[j]+a[k]+a[l]>max(max(a[i],a[l]),max(a[j],a[k]))*2)
						{
							ans++;
							ans%=998244353;
						}
					}
				}
			}
		}
	}
	if (n>=5)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							if (a[i]+a[j]+a[k]+a[l]+a[m]>max(a[m],max(max(a[i],a[l]),max(a[j],a[k])))*2)
							{
								ans++;
								ans%=998244353;
							}
						}
					
					}
				}
			}
		}
	}
	if (n>=6)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							for (long long o=m+1;o<=n;o++)
							{
								if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>max(max(a[m],a[o]),max(max(a[i],a[l]),max(a[j],a[k])))*2)
								{
									ans++;
									ans%=998244353;
								}
							}
						}
					}
				}
			}
		}
	}
	if (n>=7)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							for (long long o=m+1;o<=n;o++)
							{
								for (long long p=o+1;p<=n;p++)
								{
									if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>max(max(a[m],max(a[o],a[p])),max(max(a[i],a[l]),max(a[j],a[k])))*2)
									{
										ans++;
										ans%=998244353;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n>=8)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							for (long long o=m+1;o<=n;o++)
							{
								for (long long p=o+1;p<=n;p++)
								{
									for (long long q=p+1;q<=n;q++)
									{
										if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>max(max(max(a[m],a[q]),max(a[o],a[p])),max(max(a[i],a[l]),max(a[j],a[k])))*2)
										{
											ans++;
											ans%=998244353;
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
	if (n>=9)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							for (long long o=m+1;o<=n;o++)
							{
								for (long long p=o+1;p<=n;p++)
								{
									for (long long q=p+1;q<=n;q++)
									{
										for (long long r=q+1;r<=n;r++)
										{
											if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>max(max(max(a[m],max(a[r],a[q])),max(a[o],a[p])),max(max(a[i],a[l]),max(a[j],a[k])))*2)
											{
												ans++;
												ans%=998244353;
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
	if (n>=10)
	{
		for (long long i=1;i<=n;i++)
		{
			for (long long j=i+1;j<=n;j++)
			{
				for (long long k=j+1;k<=n;k++)
				{
					for (long long l=k+1;l<=n;l++)
					{
						for (long long m=l+1;m<=n;m++)
						{
							for (long long o=m+1;o<=n;o++)
							{
								for (long long p=o+1;p<=n;p++)
								{
									for (long long q=p+1;q<=n;q++)
									{
										for (long long r=q+1;r<=n;r++)
										{
											for (long long s=r+1;s<=n;s++)
											{
												if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[r]+a[q]+a[s]>max(max(max(a[m],max(a[r],max(a[q],a[s]))),max(a[o],a[p])),max(max(a[i],a[l]),max(a[j],a[k])))*2)
												{
													ans++;
													ans%=998244353;
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
	cout<<ans%998244353;
	return 0;
}
