#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int l[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)
    	{
    		if(l[j]<l[i])
    		{
    			int temp=l[i];
    			l[i]=l[j];
    			l[j]=temp;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(l[i]+l[j]+l[k]>l[k]*2)
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
				for(int w=k+1;w<=n;w++)
				{
				    if(l[i]+l[j]+l[k]+l[w]>l[w]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						if(l[i]+l[j]+l[k]+l[w]+l[q]>l[q]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]>l[a]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]>l[b]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]>l[c]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]>l[d]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]>l[e]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]>l[f]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]>l[g]*2)
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
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]>l[h]*2)
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
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]>l[o]*2)
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
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]>l[p]*2)
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
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												for(int r=p+1;r<=n;r++)
												{	
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]+l[r]>l[r]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												for(int r=p+1;r<=n;r++)
												{	
												for(int s=r+1;s<=n;s++)
												{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]+l[r]+l[s]>l[s]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												for(int r=p+1;r<=n;r++)
												{	
												for(int s=r+1;s<=n;s++)
												{
													for(int t=s+1;t<=n;t++)
													{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]+l[r]+l[s]+l[t]>l[t]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												for(int r=p+1;r<=n;r++)
												{	
												for(int s=r+1;s<=n;s++)
												{
													for(int t=s+1;t<=n;t++)
													{
														for(int u=t+1;u<=n;u++)
														{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]+l[r]+l[s]+l[t]+l[u]>l[u]*2)
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
				for(int w=k+1;w<=n;w++)
				{
					for(int q=w+1;q<=n;q++)
					{
						for(int a=q+1;a<=n;a++)
						{
							for(int b=a+1;b<=n;b++)
							{
								for(int c=b+1;c<=n;c++)
								{
									for(int d=c+1;d<=n;d++)
									{
										for(int e=d+1;e<=n;e++)
										{
											for(int f=e+1;f<=n;f++)
											{
												for(int g=f+1;g<=n;g++)
												{		
												for(int h=g+1;h<=n;h++)
												{		
												for(int o=h+1;o<=n;o++)
												{	
												for(int p=o+1;p<=n;p++)
												{
												for(int r=p+1;r<=n;r++)
												{	
												for(int s=r+1;s<=n;s++)
												{
													for(int t=s+1;t<=n;t++)
													{
														for(int u=t+1;u<=n;u++)
														{
															for(int v=u+1;v<=n;v++)
															{
							if(l[i]+l[j]+l[k]+l[w]+l[q]+l[a]+l[b]+l[c]+l[d]+l[e]+l[f]+l[g]+l[h]+l[o]+l[p]+l[r]+l[s]+l[t]+l[u]+l[v]>l[v]*2)
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
						}
				        }
				        }
							}
						}
					}
			    }
			}
	int ans=sum%998244353;
	cout<<ans;
	return 0;
}
