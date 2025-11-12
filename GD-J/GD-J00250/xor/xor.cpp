#include<iostream>
#include<cmath>
using namespace std;
long long sum[1005][1005];
long long a[500005];
int f(int zz,int ww,int qq)
{
	int num1[10005]={0},num2[10005]={0},num3[10005]={0};
	int v=a[zz],u=sum[qq][ww];
	int i=0;
	while(v>0||u>0)
	{
		i++;
		num1[i]=v%2;
		num2[i]=u%2;
		v/=2;
		u/=2;
	}
	for(int j=1;j<=i;j++)
	{
		if(num1[j]==num2[j])
		{
			num3[j]=0;
		}
		else
		{
			num3[j]=1;
		}
	}
	while(i>1)
	{
		i--;
		num3[i]+=num3[i+1]*2;
	}
	return num3[1];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=min(n,1001);i++)
	{
		sum[i][i]=a[i];
	}
	for(int i=1;i<=min(n,1001);i++)
	{
		for(int j=i+1;j<=min(n,1001);j++)
		{
			sum[i][j]=f(j,j-1,i);
		}
	}
	int st=1;
	long long ans=0;
	for(int i=1;i<=min(n,1001);i++)
	{
		for(int j=st;j<=i;j++)
		{
			if(sum[j][i]==k)
			{
				ans++;
				//cout<<i<<" "<<j<<endl;
				st=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
