#include<bits/stdc++.h>
using namespace std;
int make[200000+5][23];
int seta[25]={0};
int sum[25];
int change(int x,int i)
{
	int use=x,q[25]={0},j=1;
	while(use)
	{
		
		if(use%2==0)
			q[j]=0;
		else
			q[j]=1;
		use/=2;
		j++;
	}
	if(q[j]==0)
	{
		q[j]=1;
	}
	seta[i]=j-1;
	for(int z=1;z<=j;z++)
	{
		make[i][j-z]=q[z];
	}
}
int w(int w)
{
	for(int i=1;i<=25;i++)
	{
		if(sum[i]==make[w][i])
			sum[i]=0;
		else
			sum[i]=1;
	}
}
int ck()
{
	for(int i=1;i<=25;i++)
	{
		if(make[0][i]!=sum[i])
			return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	change(k,0);
	int a[n+5]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		change(a[i],i);
	}
	int ans=0;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				ans++;
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				ans++;
		cout<<ans;
		return 0;
	}

	int head=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==k)
		{
			head=i+1;
			ans++;
		}
		w(i);
		if(ck)
		{
			head=i+1;
			ans++;	}
	}
	cout<<ans;
	return 0;
}
