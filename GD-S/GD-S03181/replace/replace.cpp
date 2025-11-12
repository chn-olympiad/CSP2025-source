#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long  T,n,a[2302][2005],b[2305][2005],k[2305],c[2305],num[2305],q;
char s[500006];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n*2;i++)
	{
		cin>>s;
		int l=strlen(s);
		for(int j=1;j<=l;j++)
		{
			a[j][i]=s[j-1]-'a'+1;
			
		}
		
	}
	for(int i=1;i<=q*2;i++)
	{
		cin>>s;
		int l=strlen(s);
		for(int j=1;j<=l;j++)
		{
			b[j][i]=s[j-1]-'a'+1;
			//cout<<b[j][i]<<" ";
		}
		k[i]=strlen(s);
		//cout<<endl;
	}
	
	//cout<<endl;
	for(int i=1;i<=q*2;i+=2)
	{
		for(int r=1;r<=n*2;r+=2)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(a[1][r]==b[j][i])////////
				{
					for(int m=1;m<j;m++)
					{
						c[m]=b[m][i];
					}
					for(int m=j;m<=k[i];m++)
					{
						if(a[m-j+1][r+1]!=0)
							c[m]=a[m-j+1][r+1];
						else
							c[m]=b[m][i];
					}
					
					int temp=0;
					for(int m=1;m<=k[i];m++)
					{
						if(c[m]!=b[m][i+1])
						{
							temp=1;
						}
					}
					if(a[k[i]-j+1+1][r+1]!=0)
					{
						temp=1;
					}
					if(temp==0)
					{
						num[i]+=1;
					}
				}
			}
		}
		
	}
	for(int i=1;i<=q*2;i+=2)
	{
		cout<<num[i]<<endl;
	}
}
/*
for(int m=1;m<=k[i];m++)
		{
			cout<<b[m][i]<<"  ";
		}
		cout<<endl;*/
