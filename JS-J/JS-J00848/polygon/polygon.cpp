#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5007];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	else if(n==2)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}
				}
			}
		}
		cout<<sum;
		return 0;
	}
	else if(n==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
					}
				}
			}
		}
		if(max(max(a[1],a[2]),max(a[3],a[4]))*2<a[1]+a[2]+a[3]+a[4])
		{
			sum++;
		}
		cout<<sum;
		return 0;
	}
	else if(n==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
						}
					}
				}
			}
		}
		if(max(a[5],max(a[4],max(a[3],max(a[2],a[1]))))*2<a[1]+a[2]+a[3]+a[4]+a[5])
		{
			sum++;
		}
		cout<<sum<<endl;
		return 0;
	}
	else if(n==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
							}
						}
					}
				}
			}
		}
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6])
		{
			sum++;
		}
		cout<<sum<<endl;
		return 0;
	}
	else if(n==7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
		if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
		{
			sum++;
		}
		cout<<sum;
		return 0;
	}
	else if(n==8)
	{
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(max(a[5],a[6]),max(a[8],a[7]))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])
		{
			sum++;
		}
		cout<<sum;
		return 0;
	}
	else if(n==9)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										if(max(a[i],max(a[j],max(a[k],max(a[l],max(max(a[z],a[o]),max(a[m],a[p]))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o])
										{
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(max(a[6],a[7]),max(a[8],a[9])))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9])
		{
			sum++;
		}
		cout<<sum;
		return 0;
	}
	else if(n==10)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										if(max(a[i],max(a[j],max(a[k],max(a[l],max(max(a[z],a[o]),max(a[m],a[p]))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o])
										{
											sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(max(a[p],a[m]),max(a[u],a[z])))))))*2<a[i]+a[j]+a[l]+a[k]+a[m]+a[p]+a[o]+a[z]+a[u])
											{
												sum++;
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
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(max(a[6],a[7]),max(a[8],max(a[9],a[10]))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10])
		{
			sum++;
		}
		cout<<sum;
		return 0;
	}
	else if(n==11)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										if(max(a[i],max(a[j],max(a[k],max(a[l],max(max(a[z],a[o]),max(a[m],a[p]))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o])
										{
											sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(max(a[p],a[m]),max(a[u],a[z])))))))*2<a[i]+a[j]+a[l]+a[k]+a[m]+a[p]+a[o]+a[z]+a[u])
											{
												sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(max(a[u],a[y]),max(a[o],max(a[p],a[z]))))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o]+a[u]+a[y])
												{
													sum++;
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
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(max(a[6],a[7]),max(a[8],max(a[9],max(a[10],a[11])))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11])
		{
			sum++;
		}
	}
	else if(n==12)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										if(max(a[i],max(a[j],max(a[k],max(a[l],max(max(a[z],a[o]),max(a[m],a[p]))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o])
										{
											sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(max(a[p],a[m]),max(a[u],a[z])))))))*2<a[i]+a[j]+a[l]+a[k]+a[m]+a[p]+a[o]+a[z]+a[u])
											{
												sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(max(a[u],a[y]),max(a[o],max(a[p],a[z]))))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o]+a[u]+a[y])
												{
													sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												for(int g=y+1;g<=n;g++)
												{
													if(max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(max(a[m],a[p]),max(a[o],max(a[y],max(a[g],a[u])))))))))*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[z]+a[o]+a[p]+a[y]+a[u]+a[g])
													{
														sum++;
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
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(max(a[6],a[7]),max(a[8],max(a[9],max(a[10],max(a[11],a[12]))))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12])
		{
			sum++;
		}
	}
	else if(n==13)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
					{
						sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						if(max(max(a[i],a[j]),max(a[k],a[z]))*2<a[i]+a[j]+a[k]+a[z])
						{
							sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							if(max(a[i],max(a[j],max(a[k],max(a[z],a[l]))))*2<a[i]+a[j]+a[k]+a[l]+a[z])
							{
								sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],a[o])))))*2<a[i]+a[j]+a[k]+a[l]+a[z]+a[o])
								{
									sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									if(max(a[1],max(a[2],max(a[3],max(max(a[4],a[5]),max(a[6],a[7])))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7])
									{
										sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										if(max(a[i],max(a[j],max(a[k],max(a[l],max(max(a[z],a[o]),max(a[m],a[p]))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o])
										{
											sum++;
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
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(max(a[p],a[m]),max(a[u],a[z])))))))*2<a[i]+a[j]+a[l]+a[k]+a[m]+a[p]+a[o]+a[z]+a[u])
											{
												sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(max(a[u],a[y]),max(a[o],max(a[p],a[z]))))))))*2<a[i]+a[j]+a[k]+a[z]+a[l]+a[m]+a[p]+a[o]+a[u]+a[y])
												{
													sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												for(int g=y+1;g<=n;g++)
												{
													if(max(a[i],max(a[j],max(a[k],max(a[z],max(a[l],max(max(a[m],a[p]),max(a[o],max(a[y],max(a[g],a[u])))))))))*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[z]+a[o]+a[p]+a[y]+a[u]+a[g])
													{
														sum++;
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
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int z=k+1;z<=n;z++)
					{
						for(int l=z+1;l<=n;l++)
						{
							for(int o=l+1;o<=n;o++)
							{
								for(int p=o+1;p<=n;p++)
								{
									for(int m=p+1;m<=n;m++)
									{
										for(int u=m+1;u<=n;u++)
										{
											for(int y=u+1;y<=n;y++)
											{
												for(int g=y+1;g<=n;g++)
												{
													for(int e=g+1;e<=n;e++)
													{
														if(max(a[i],max(a[j],max(a[k],max(a[l],max(a[z],max(max(a[o],a[p]),max(a[m],max(a[g],max(a[u],max(a[y],a[e]))))))))))*2<a[i]+a[j]+a[k]+a[l]+a[m]+a[z]+a[o]+a[p]+a[g]+a[y]+a[u]+a[e])
													{
															sum++;
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
		if(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(max(a[6],a[7]),max(a[8],max(a[9],max(a[10],max(a[11],max(a[12],a[13])))))))))))*2<a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13])
		{
				sum++;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
