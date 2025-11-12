#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("pojygon.in","r"stdin);
	freopen("pojygon.out","w"stdout);
	int n,n[5000],b,c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>n[i];
	}
	b=n[0]
	for(int i=0;i<n;i++)
	{
		if(n[i])<n[i+1])
		{
			b==n[i+1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<n-2;k++)
		{
			if(n[i]+n[k+1]+n[k+2]>b*2)
			{
				c=c+1;
			}
		}
	if(n>=4)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-3;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=5)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-4;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=6)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-5;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=7)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-6;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=8)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-7;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=9)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-8;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=10)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-9;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=11)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-10;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]>b*2)
				{
					c=c+1;
				}
			}
		}
	}
	if(n>=12)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-11;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]+n[k+11]>b*2)
				{
					c=c+1;
				}
			}
		}
		f(n>=13)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-12;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]+n[k+11]+n[k+12]>b*2)
				{
					c=c+1;
				}
			}
		}f(n>=14)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-13;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]+n[k+11]+n[k+12]+n[k+13]>b*2)
				{
					c=c+1;
				}
			}
		}f(n>=15)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-14;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]+n[k+11]+n[k+12]+n[k+13]+n[k+14]>b*2)
				{
					c=c+1;
				}
			}
		}f(n>=16)
	{
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n-15;k++)
			{
				if(n[i]+n[k+1]+n[k+2]+n[k+3]+n[k+4]+n[k+5]+n[k+6]+n[k+7]+n[k+8]+n[k+9]+n[k+10]+n[k+11]+n[k+12]+n[k+13]+n[k+14]+n[k+15]>b*2)
				{
					c=c+1;
				}
			}
		}
	
	return 0;
}
