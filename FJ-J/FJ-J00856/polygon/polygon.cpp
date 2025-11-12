#include <bits/stdc++.h>
using namespace std;
int n,a[114514],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0<<endl;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3*2])
		{
			cout<<1;
		}
	}
	if(n==4)
	{
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
	}
	if(n==5)
	{
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
	}
	if(n==6)
	{
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
	}
	if(n==7)
	{
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[3]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[4]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[3]+a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[3]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[4]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[4]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
		if(a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7])
		{
			ans++;
		}
	}
	if(n==8)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i]+a[j]+a[k]>2*a[k])
					{
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*a[l])
						{
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							if(a[i]+a[j]+a[k]+a[l]+a[g]>2*a[g])
							{
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]>2*a[q])
								{
									ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]>2*a[w])
									{
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*a[8])
		{
			ans++;
		}
	}
	if(n==9)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i]+a[j]+a[k]>2*a[k])
					{
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*a[l])
						{
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							if(a[i]+a[j]+a[k]+a[l]+a[g]>2*a[g])
							{
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]>2*a[q])
								{
									ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]>2*a[w])
									{
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									for(int e=w+1;e<=n;e++)
									{
										if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]+a[e]>2*a[e])
										{
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*a[9])
		{
			ans++;
		}
	}
	if(n==10)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i]+a[j]+a[k]>2*a[k])
					{
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*a[l])
						{
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							if(a[i]+a[j]+a[k]+a[l]+a[g]>2*a[g])
							{
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]>2*a[q])
								{
									ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]>2*a[w])
									{
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									for(int e=w+1;e<=n;e++)
									{
										if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]+a[e]>2*a[e])
										{
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int g=l+1;g<=n;g++)
						{
							for(int q=g+1;q<=n;q++)
							{
								for(int w=q+1;w<=n;w++)
								{
									for(int e=w+1;e<=n;e++)
									{
										for(int r=e+1;r<=n;r++)
										{
											if(a[i]+a[j]+a[k]+a[l]+a[g]+a[q]+a[w]+a[e]+a[r]>2*a[r])
											{
												ans++;
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
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*a[10])
		{
			ans++;
		}
	}
	cout<<ans;
}
