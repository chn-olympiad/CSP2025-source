#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("club.in");
	ofstream fout("club.out");
	int t;
	fin>>t;
	int n,s[t],xza=0,xzb=0,xzc=0;
	for(int i=1;i<=t;i++)
	{
		xza=0;
		xzb=0;
		xzc=0;
		fin>>n;
		if(n%2!=0)
		{
			break;
		}
		int a[n],b[n],c[n];
		for(int j=1;j<=n;j++)
		{
			fin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]&&a[j]>c[j])xza++;
			else if(b[j]>a[j]&&b[j]>c[j])xzb++;
			else if(c[j]>a[j]&&c[j]>b[j])xzc++;
		}
		for(int k=1;k<=n;k++)
		{
			if(a[k]>b[k]&&a[k]>c[k])
			{
				s[i]+=a[k];
				if(xza>n/2)
				{
					s[i]-=a[k];
					if(b[k]>c[k])
					{
						s[i]+=b[k];
						xza--;
					}
					else if(c[k]>b[k])
					{
						s[i]+=c[k];
						xza--;
					}
					else if(b[k]==c[k])
					{
						s[i]+=b[k];
						xza--;
					}
				}
			}
			if(b[k]>a[k]&&b[k]>c[k])
			{
				s[i]+=b[k];
				if(xzb>n/2)
				{
					s[i]-=b[k];
					if(a[k]>c[k])
					{
						s[i]+=a[k];
						xzb--;
					}
					else if(c[k]>a[k])
					{
						s[i]+=c[k];
						xzb--;
					}
					else if(a[k]==c[k])
					{
						s[i]+=a[k];
						xzb--;
					}
				}
			}
			if(c[k]>a[k]&&c[k]>b[k])
			{
				s[i]+=c[k];
				if(xzc>n/2)
				{
					s[i]-=c[k];
					if(a[k]>b[k])
					{
						s[i]+=a[k];
						xzc--;
					}
					else if(b[k]>a[k])
					{
						s[i]+=b[k];
						xzc--;
					}
					else if(a[k]==b[k])
					{
						s[i]+=a[k];
						xzc--;
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++)fout<<s[i]<<endl;
	return 0;
 } 
