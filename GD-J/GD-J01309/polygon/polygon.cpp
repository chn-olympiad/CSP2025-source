#include<bits/stdc++.h>
using namespace std;
int n,s[15],ans;

int is3(int x,int y,int z)
{
	int maxn=max({x,y,z}),sum=x+y+z;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is4(int x,int y,int z,int a)
{
	int maxn=max({x,y,z,a}),sum=x+y+z+a;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is5(int x,int y,int z,int a,int b)
{
	int maxn=max({x,y,z,a,b}),sum=x+y+z+a+b;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is6(int x,int y,int z,int a,int b,int c)
{
	int maxn=max({x,y,z,a,b,c}),sum=x+y+z+a+b+c;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is7(int x,int y,int z,int a,int b,int c,int d)
{
	int maxn=max({x,y,z,a,b,c,d}),sum=x+y+z+a+b+c+d;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is8(int x,int y,int z,int a,int b,int c,int d,int e)
{
	int maxn=max({x,y,z,a,b,c,d,e}),sum=x+y+z+a+b+c+d+e;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is9(int x,int y,int z,int a,int b,int c,int d,int e,int f)
{
	int maxn=max({x,y,z,a,b,c,d,e,f}),sum=x+y+z+a+b+c+d+e+f;
	if(sum>2*maxn)	return 1;
	return 0;
}

int is10(int x,int y,int z,int a,int b,int c,int d,int e,int f,int g)
{
	int maxn=max({x,y,z,a,b,c,d,e,f,g}),sum=x+y+z+a+b+c+d+e+f+g;
	if(sum>2*maxn)	return 1;
	return 0;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>s[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
				ans+=is3(s[i],s[j],s[k]);
		}
	}
	
	for(int i=1;i<=n-3;i++)
	{
		for(int j=i+1;j<=n-2;j++)
		{
			for(int k=j+1;k<=n-1;k++)
			{
				for(int l=k+1;l<=n;l++)
					ans+=is4(s[i],s[j],s[k],s[l]);
			}
		}
	}
	
	for(int i=1;i<=n-4;i++)
	{
		for(int j=i+1;j<=n-3;j++)
		{
			for(int k=j+1;k<=n-2;k++)
			{
				for(int l=k+1;l<=n-1;l++)
				{
					for(int m=l+1;m<=n;m++)
						ans+=is5(s[i],s[j],s[k],s[l],s[m]); 
				}
			}
		}
	}
	
	for(int i=1;i<=n-5;i++)
	{
		for(int j=i+1;j<=n-4;j++)
		{
			for(int k=j+1;k<=n-3;k++)
			{
				for(int l=k+1;l<=n-2;l++)
				{
					for(int m=l+1;m<=n-1;m++)
					{
						for(int o=m+1;o<=n;o++)
							ans+=is6(s[i],s[j],s[k],s[l],s[m],s[o]);
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n-6;i++)
	{
		for(int j=i+1;j<=n-5;j++)
		{
			for(int k=j+1;k<=n-4;k++)
			{
				for(int l=k+1;l<=n-3;l++)
				{
					for(int m=l+1;m<=n-2;m++)
					{
						for(int o=m+1;o<=n-1;o++)
						{
							for(int p=o+1;p<=n;p++)
								ans+=is7(s[i],s[j],s[k],s[l],s[m],s[o],s[p]);
						}
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n-7;i++)
	{
		for(int j=i+1;j<=n-6;j++)
		{
			for(int k=j+1;k<=n-5;k++)
			{
				for(int l=k+1;l<=n-4;l++)
				{
					for(int m=l+1;m<=n-3;m++)
					{
						for(int o=m+1;o<=n-2;o++)
						{
							for(int p=o+1;p<=n-1;p++)
							{
								for(int q=p+1;q<=n;q++)
									ans+=is8(s[i],s[j],s[k],s[l],s[m],s[o],s[p],s[q]);
							}
						}
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n-8;i++)
	{
		for(int j=i+1;j<=n-7;j++)
		{
			for(int k=j+1;k<=n-6;k++)
			{
				for(int l=k+1;l<=n-5;l++)
				{
					for(int m=l+1;m<=n-4;m++)
					{
						for(int o=m+1;o<=n-3;o++)
						{
							for(int p=o+1;p<=n-2;p++)
							{
								for(int q=p+1;q<=n-1;q++)
								{
									for(int r=q+1;r<=n;r++)
										ans+=is9(s[i],s[j],s[k],s[l],s[m],s[o],s[p],s[q],s[r]);
								}
							}
						}
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n-9;i++)
	{
		for(int j=i+1;j<=n-8;j++)
		{
			for(int k=j+1;k<=n-7;k++)
			{
				for(int l=k+1;l<=n-6;l++)
				{
					for(int m=l+1;m<=n-5;m++)
					{
						for(int o=m+1;o<=n-4;o++)
						{
							for(int p=o+1;p<=n-3;p++)
							{
								for(int q=p+1;q<=n-2;q++)
								{
									for(int r=q+1;r<=n-1;r++)
									{
										for(int t=r+1;t<=n;t++)
											ans+=is10(s[i],s[j],s[k],s[l],s[m],s[o],s[p],s[q],s[r],s[t]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout<<ans;
	return 0;
} 
