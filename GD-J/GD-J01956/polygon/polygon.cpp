#include <bits/stdc++.h>
using namespace std;
long long zjy(int n,int a[],int s,int b[],int l,int ll)
{
	long long num=0;
    
	for(int i=ll;i<n;i++)
	{
		b[l]=a[i];
		if(l!=s-1)
		{
			num+=zjy(n,a,s,b,l+1,i+1);
		}
		else
		{
			int all=0,maxn=-1;
			for(int j=0;j<s;j++)
			{
				all+=b[j];
				maxn=max(maxn,b[j]);
			}
			if(all>maxn*2)
			{
				num++;
			}
		}
		
	}
	
	return num;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	int a[n+1],b[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	for(int s=3;s<=n;s++)
	{
		sum+=zjy(n,a,s,b,0,0);
	}
	cout<<sum%998244353;
	return 0;
}
