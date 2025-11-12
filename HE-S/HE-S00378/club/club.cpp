#include<bits/stdc++.h>
using namespace std;

int max_0(int a,int b,int c)
{
	if(a>b&&a==c)
	{
		return a;
	}
	if(a>c&&a==b)
	{
		return a;
	}
	if(b>a&&b==c)
	{
		return b;
	}
	if(b>c&&b==a)
	{
		return b;
	}
	if(c>a&&c==b)
	{
		return c;
	}
	if(c>b&&c==a)
	{
		return a;
	}
	return -1;
}

int max_1(int a,int b,int c)
{
	if(a>b&&a>c)
	{
		return a;
	}
	if(b>a&&b>c)
	{
		return b;
	}
	if(c>a&&c>b)
	{
		return c;
	}
	return -1;
}

int max_2(int a,int b,int c)
{
	if(a<b&&a>=c)
	{
		return a;
	}
	if(a>=b&&a<c)
	{
		return a;
	}
	if(b<a&&b>=c)
	{
		return b;
	}
	if(b>=a&&b<c)
	{
		return b;
	}
	if(c<a&&c>=b)
	{
		return c;
	}
	if(c>=a&&c<b)
	{
		return c;
	}
	return -1;
}

int shai_2(int a,int b,int c,int n,int sum,int m[],int fen[])
{
	int max_sum=-1,ji=0;
	if(a>n/2)
	{
		while(a>n/2)
		{
			if(ji==0)
			{
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && a>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3+1])
						{
							fen[i]=2;
							a--;
							break;
						}
						if(max2==m[(fen[i]-1)*3+2])
						{
							fen[i]=3;
							a--;
							break;
						}
					}
				}
			}
			else
			{
				int r_sum=max_sum;
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && a>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=r_sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=r_sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3+1])
						{
							fen[i]=2;
							a--;
						}
						if(max2==m[(fen[i]-1)*3+2])
						{
							fen[i]=3;
							a--;
						}
					}
				}
			}
			ji++;
		}
		
		return max_sum;
	}
	if(b>n/2)
	{
		while(b>n/2)
		{
			if(ji==0)
			{
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && b>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3])
						{
							fen[i]=1;
							b--;
							break;
						}
						if(max2==m[(fen[i]-1)*3+2])
						{
							fen[i]=3;
							b--;
							break;
						}
					}
				}
			}
			else
			{
				int r_sum=max_sum;
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && b>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=r_sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=r_sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3])
						{
							fen[i]=1;
							b--;
						}
						if(max2==m[(fen[i]-1)*3+2])
						{
							fen[i]=3;
							b--;
						}
					}
				}
			}
			ji++;
		}
		
		return max_sum;
	}
	if(c>n/2)
	{
		while(c>n/2)
		{
			if(ji==0)
			{
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && c>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3])
						{
							fen[i]=1;
							c--;
							break;
						}
						if(max2==m[(fen[i]-1)*3+1])
						{
							fen[i]=2;
							c--;
							break;
						}
					}
				}
			}
			else
			{
				int r_sum=max_sum;
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(fen[i]=2 && c>n/2)
					{
						if(sum-max1+max2>=max_sum)
						{
							max_sum=r_sum-max1+max2;
						}
					}
				}
				for(int i=0;i<n;i++)
				{
					int max1=max_1(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					int max2=max_2(m[(fen[i]-1)*3],m[(fen[i]-1)*3+1],m[(fen[i]-1)*3+2]);
					if(max_sum=r_sum-max1+max2)
					{
						
						if(max2==m[(fen[i]-1)*3])
						{
							fen[i]=1;
							c--;
						}
						if(max2==m[(fen[i]-1)*3+1])
						{
							fen[i]=2;
							c--;
						}
					}
				}
			}
			ji++;
		}
		
		return max_sum;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int sum_zong[t+1];
	for(int x=0;x<t;x++)
	{
		int n,sum=0,a=0,b=0,c=0;
		cin>>n;
		int m[n*3+1],fen[n+1];
		for(int i=0;i<n*3;i++)
		{
			cin>>m[i];
		}
		for(int i=0;i<n*3;i+=3)
		{
			int max=max_1(m[i],m[i+1],m[i+2]);
			if(max>0)
			{
				if(max==m[i])
				{
					fen[i/3]=1;
					sum+=max;
					a++;
				}
				if(max==m[i+1])
				{
					fen[i/3]=2;
					sum+=max;
					b++;
				}
				if(max==m[i+2])
				{
					fen[i/3]=3;
					sum+=max;
					c++;
				}
			}
			else
			{
				max=max_0(m[i],m[i+1],m[i+2]);
				if(a+1<=n/2 && max==m[i])
				{
					fen[i/3]=1;
					sum+=max;
					a++;
				}
				else if(b+1<=n/2 && max==m[i+1])
				{
					fen[i/3]=2;
					sum+=max;
					b++;
				}
				else if(c+1<=n/2 && max==m[i+2])
				{
					fen[i/3]=3;
					sum+=max;
					c++;
				}
			} 
		}
		if(a>n/2 || b>n/2 || c>n/2)
		{
			sum = shai_2(a,b,c,n,sum,m,fen);
		}
		sum_zong[x]=sum;
	}
	for(int x=0;x<t;x++)
	{
		cout<<sum_zong[x]<<endl;
	}
	
	return 0;
}

