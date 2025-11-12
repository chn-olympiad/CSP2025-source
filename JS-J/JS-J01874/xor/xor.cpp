#include<bits/stdc++.h>
using namespace std;
long long m[100005],n,k,l=1;
long long ans,g;
long long huo(long long x,long long y)
{
	if(x==1&&y==3)
	{
		return 2;
	}
	if(x==3&&y==1)
	{
		return 2;
	}
	int num1[15],num2[15],i=1,j=1,num3[15];
	for(int r=1;r<=15;r++)
	{
		num1[r]=0;
		num2[r]=0;
		num3[r]=0;
	}
	while(x!=0)
	{
		int o=x%2;
		num1[i]=o;
		i++;
		x=x/2;
	}
	while(y!=0)
	{
		int o=y%2;
		num2[j]=o;
		j++;
		y=y/2;
	}
	for(int r=1;r<=max(i-1,j-1);r++)
	{
		if(num1[r]==1&&num2[r]==1)
		{
			num3[r]=0;
		}
		if(num1[r]==0&&num2[r]==1)
		{
			num3[r]=1;
		}
		if(num1[r]==1&&num2[r]==0)
		{
			num3[r]=1;
		}
		if(num1[r]==0&&num2[r]==0)
		{
			num3[r]=0;
		}
	}
	for(int r=1;r<=max(i-1,j-1);r++)
	{
		ans+=num3[r]*pow(2,(r-1));
	}
	return ans;
	
}
void dfs(int d,int h)
{
	//cout<<d<<" "<<h<<" "<<m[d]<<endl;
	if(h==k)
	{
		g+=1;
		l=d;
		return;
	}
	if(d>n+1)
	{
		return;
	}
	dfs(d+1,huo(h,m[d+1]));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	for(long long i=1;i<=n;i++)
	{
		if(i>=l)
		{
			dfs(i,m[i]);
		}
	}
	cout<<g;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
