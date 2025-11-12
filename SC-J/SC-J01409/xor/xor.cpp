#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e5+10;
int c(int m,int d)
{
	int num1=1,num2=1;
	for(int i=1;i<=m;i++)
	{
		num1*=d-i+1,num2*=i;
	}
	return num1/num2;
}
int a[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);//正式提交 
	int n,k;
	bool flag_A=1,flag_B=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag_A=0; 
			if(a[i]!=0) flag_B=0;
		} 
	}
	if(flag_A)
	{
		cout<<n/2;
		return 0;
	}//10pts
	else if(flag_B)
	{
		int ans=0;
		if(k)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i-1]==1&&!vis[i-1])
				{
					ans++;
					vis[i]=vis[i-1]=1;
				}
			}
		}
		cout<<ans;
	}//20pts
	else
	{
		int ans=0;
		int i=1,j=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int x=a[i];
				for(int p=i+1;p<=j;p++)
				{
					x=x^a[p];
				}
				if(x==k) ans++,i=j+1; 
			}
		}
		cout<<ans;
	}//期望35pts(加上面) 
	return 0;
}