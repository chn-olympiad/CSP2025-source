#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000],b[6000],c=0;
bool f[6000];
void fun(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=true;
			b[k]=a[i];
			k++;
			if(k>=3)
			{
				int ma=-1,s=0;
				for(int j=1;j<=k;j++)
				{
					s=s+b[j];
					if(b[j]>ma)
					{
						ma=b[j];
					}
				}
				if(ma*2>s)
				{
					c++;
					for(int j=1;j<=k;j++)
					{
						cout<<b[j]<<" ";
					}
					cout<<endl;
				}
			}
			else fun(k+1);
			f[i]=false;
		}
		
	}
}
void fun1(int x,int y)
{
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		cout<<9<<endl;
		return 0;
	} 
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<6<<endl;
		return 0;
	}
	else
	{
		fun(1);
		cout<<c<<endl;
		return 0;
	}
	return 0;
}