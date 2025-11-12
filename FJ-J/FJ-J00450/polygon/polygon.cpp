#include<bits/stdc++.h>
using namespace std;
int a[10005],s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,zd=-11;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>zd)
		{
			zd=a[i];
		}
	}
	for(int bs=3;bs<=n;bs++)
	{
		if(bs==3)
		{	
			for(int i=1;i<=n-2;i++)
			{
				for(int j=i+1;j<=n-1;j++)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(a[i]+a[j]+a[k]>max(max(a[i],a[j]),a[k])*2)
						{
							s++;
						}
					}
				}
			}
		}
		if(bs==4)
		{	
			for(int i=1;i<=n-3;i++)
			{
				for(int j=i+1;j<=n-2;j++)
				{
					for(int k=j+1;k<=n-1;k++)
					{
						for(int p=k+1;p<=n;p++)
						{
							if(a[i]+a[j]+a[k]+a[p]>max(a[p],max(max(a[i],a[j]),a[k]))*2)
							{
								s++;
							}
						}
					}	
				}
			}
		}
		if(bs==5)
		{	
			for(int i=1;i<=n-4;i++)
			{
				for(int j=i+1;j<=n-3;j++)
				{
					for(int k=j+1;k<=n-2;k++)
					{
						for(int p=k+1;p<=n-1;p++)
						{
							for(int u=p+1;u<=n;u++)
							{
								if(a[u]+a[i]+a[j]+a[k]+a[p]>max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u])*2)
								{
									s++;
								}
							}
						}
					}
				}
			}
		}
		if(bs==6)
		{	
			for(int i=1;i<=n-5;i++)
			{
				for(int j=i+1;j<=n-4;j++)
				{
					for(int k=j+1;k<=n-3;k++)
					{
						for(int p=k+1;p<=n-2;p++)
						{
							for(int u=p+1;u<=n-1;u++)
							{
								for(int y=u+1;y<=n;y++)
								{
									if(a[u]+a[i]+a[j]+a[k]+a[p]+a[y]>max(max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u]),a[y])*2)
									{
										s++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(bs==7)
		{	
			for(int i=1;i<=n-6;i++)
			{
				for(int j=i+1;j<=n-5;j++)
				{
					for(int k=j+1;k<=n-4;k++)
					{
						for(int p=k+1;p<=n-3;p++)
						{
							for(int u=p+1;u<=n-2;u++)
							{
								for(int y=u+1;y<=n-1;y++)
								{
									for(int t=y+1;t<=n;t++)
									{
										if(a[u]+a[i]+a[j]+a[k]+a[p]+a[y]+a[t]>max(max(max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u]),a[y]),a[t])*2)
										{
											s++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(bs==8)
		{	
			for(int i=1;i<=n-7;i++)
			{
				for(int j=i+1;j<=n-6;j++)
				{
					for(int k=j+1;k<=n-5;k++)
					{
						for(int p=k+1;p<=n-4;p++)
						{
							for(int u=p+1;u<=n-3;u++)
							{
								for(int y=u+1;y<=n-2;y++)
								{
									for(int t=y+1;t<=n-1;t++)
									{
										for(int r=t+1;r<=n;r++)
										{
											if(a[u]+a[i]+a[j]+a[k]+a[p]+a[y]+a[t]+a[r]>max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u]),a[y]),a[t]),a[r])*2)
											{
												s++;
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
		if(bs==9)
		{	
			for(int i=1;i<=n-8;i++)
			{
				for(int j=i+1;j<=n-7;j++)
				{
					for(int k=j+1;k<=n-6;k++)
					{
						for(int p=k+1;p<=n-5;p++)
						{
							for(int u=p+1;u<=n-4;u++)
							{
								for(int y=u+1;y<=n-3;y++)
								{
									for(int t=y+1;t<=n-2;t++)
									{
										for(int r=t+1;r<=n-1;r++)
										{
											for(int e=r+1;e<=n;e++)
											{
												if(a[u]+a[i]+a[j]+a[k]+a[p]+a[y]+a[t]+a[r]+a[e]>max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u]),a[y]),a[t]),a[r]),a[e])*2)
												{
													s++;
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
		if(bs==10)
		{	
			for(int i=1;i<=n-9;i++)
			{
				for(int j=i+1;j<=n-8;j++)
				{
					for(int k=j+1;k<=n-7;k++)
					{
						for(int p=k+1;p<=n-6;p++)
						{
							for(int u=p+1;u<=n-5;u++)
							{
								for(int y=u+1;y<=n-4;y++)
								{
									for(int t=y+1;t<=n-3;t++)
									{
										for(int r=t+1;r<=n-2;r++)
										{
											for(int e=r+1;e<=n-1;e++)
											{
												for(int w=e+1;w<=n;w++)
												{
													if(a[u]+a[i]+a[j]+a[k]+a[p]+a[y]+a[t]+a[r]+a[e]+a[w]>max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[p]),a[u]),a[y]),a[t]),a[r]),a[e]),a[w])*2)
													{
														s++;
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
	cout<<s;
	return 0;
}
