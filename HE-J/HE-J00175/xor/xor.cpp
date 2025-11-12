#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,num=0,z=0;
	cin>>n>>k;
	int a[n+1]={0};
	int r[n+1],w[n+1];
	for(int i=1;i<=n;i++)  
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=a[i];
		for(int j=i;j<=n;j++)
		{
			if((ans==k&&i==j)||(ans|a[j]==k&&i!=j))
			{
				num++;
				i=j;
				r[num]=a[i];
				w[num]=a[j];
			}
			ans=ans|a[j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n-i;j++)
		{
			if(w[i]<w[j]) 
			{
				swap(w[i],w[j]);
				swap(r[i],r[j]);
			}
		}
	}
	k=-1;
	for(int i=1;i<=num;i++)
	{
		if(r[i]>k) 
		{
			z++;
			k=w[i];
		}
		
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
