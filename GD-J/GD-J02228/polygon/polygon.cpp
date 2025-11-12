#include <bits/stdc++.h>
using namespace std;
int a[5005],sum[5005];
long long mod=998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]<=a[3]*2)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else if(n==4)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		cout<<ans;
	}
	else if(n==5)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		cout<<ans;
	}
	else if(n==6)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							if(a[i]+a[j]+a[k]+a[b]+a[c]>a[c]*2) ans++;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		cout<<ans;
	}
	else if(n==7)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							if(a[i]+a[j]+a[k]+a[b]+a[c]>a[c]*2) ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>a[d]*2) ans++;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		cout<<ans;
	}
	else if(n==8)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							if(a[i]+a[j]+a[k]+a[b]+a[c]>a[c]*2) ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>a[d]*2) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>a[e]*2) ans++;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[8]*2) ans++;
		cout<<ans;
	}
	else if(n==9)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							if(a[i]+a[j]+a[k]+a[b]+a[c]>a[c]*2) ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>a[d]*2) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>a[e]*2) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									for(int f=e+1; f<=n; f++)
									{
										if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]>a[f]*2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[9]*2) ans++;
		cout<<ans;
	}
	else if(n==10)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					if(a[i]+a[j]+a[k]>a[k]*2) ans++;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						if(a[i]+a[j]+a[k]+a[b]>a[b]*2) ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							if(a[i]+a[j]+a[k]+a[b]+a[c]>a[c]*2) ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>a[d]*2) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>a[e]*2) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									for(int f=e+1; f<=n; f++)
									{
										if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]>a[f]*2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				for(int k=j+1; k<=n; k++)
				{
					for(int b=k+1; b<=n; b++)
					{
						for(int c=b+1; c<=n; c++)
						{
							for(int d=c+1; d<=n; d++)
							{
								for(int e=d+1; e<=n; e++)
								{
									for(int f=e+1; f<=n; f++)
									{
										for(int g=f+1; g<=n; g++)
										{
											if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>a[g]*2) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[10]*2) ans++;
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
