#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	if(ans==n)
	{
		int k=1;
		for(int i=1;i<=n;i++)
		{
			k*=2;
			k=k%998244353;
		}
		int p=n*(n-1)/2;
		int s=(k-n-p-1)%20+20;
		cout<<s%20;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
		for(int j=i+1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]<=a[k])
					break;
				else
				{
					sum++;
					sum%=998244353;
				}
			}
	for(int b=1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int c=1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int d=1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int e=1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int f=1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int g=1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int h=1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int l=1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int m=1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int o=1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int p=1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int q=1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int r=1;r<=n-15;r++)
	for(int q=r+1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[r]+a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int s=1;s<=n-16;s++)
	for(int r=s+1;r<=n-15;r++)
	for(int q=r+1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[s]+a[r]+a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int t=1;t<=n-17;t++)
	for(int s=t+1;s<=n-16;s++)
	for(int r=s+1;r<=n-15;r++)
	for(int q=r+1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[t]+a[s]+a[r]+a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int u=1;u<=n-18;u++)
	for(int t=u+1;t<=n-17;t++)
	for(int s=t+1;s<=n-16;s++)
	for(int r=s+1;r<=n-15;r++)
	for(int q=r+1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[u]+a[t]+a[s]+a[r]+a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	for(int v=1;v<=n-19;v++)
	for(int u=v+1;u<=n-18;u++)
	for(int t=u+1;t<=n-17;t++)
	for(int s=t+1;s<=n-16;s++)
	for(int r=s+1;r<=n-15;r++)
	for(int q=r+1;q<=n-14;q++)
	for(int p=q+1;p<=n-13;p++)
	for(int o=p+1;o<=n-12;o++)
	for(int m=o+1;m<=n-11;m++)
	for(int l=m+1;l<=n-10;l++)
	for(int h=l+1;h<=n-9;h++)
	for(int g=h+1;g<=n-8;g++)
	for(int f=g+1;f<=n-7;f++)
	for(int e=f+1;e<=n-6;e++)
	for(int d=e+1;d<=n-5;d++)
	for(int c=d+1;c<=n-4;c++)	
	for(int b=c+1;b<=n-3;b++)
		for(int i=b+1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[v]+a[u]+a[t]+a[s]+a[r]+a[q]+a[p]+a[o]+a[m]+a[l]+a[h]+a[g]+a[f]+a[e]+a[d]+a[c]+a[b]+a[i]+a[j]<=a[k])
						break;
					else
					{
						sum++;
						sum%=998244353;
					}
	cout<<sum;
	return 0;
}