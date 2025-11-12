#include<bits/stdc++.h>
using namespace std;
#define int long long

bool A=true,B=true,C=true;

int n,k,a[500005];
int sum[500005];
int ans=0;

int q(int l,int r)
{
	return sum[r]^sum[l-1];
}
void dfs(int cnt,int i_)
{
	if(i_==n+1)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(cnt+n-i_+1<=ans)
	{
		return ;
	}
	for(int i=i_;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(q(i,j)!=k)
				continue;
			dfs(cnt+1,j+1);
		}
	}
	return ;
}
void solveA()
{
	if(k==1)
		cout<<n;
	else if(k==0)
		cout<<n/2;
	else
		cout<<0;
	return ;
}
void solveB()
{
	int cnt_=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			cnt_+=a[i];
		}
		cout<<cnt_;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt_++;
			}
			else if(a[i]==1&&a[i+1]==1&&i!=n)
			{
				cnt_++;
				i++;
			}
		}
		cout<<cnt_;
	}
	else
	{
		cout<<0;
	}
	return ;
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			A=false;
		}
		if(a[i]!=0&&a[i]!=1)
		{
			B=false;
		}
		sum[i]=sum[i-1]^a[i];
	}
	if(A)
	{
		solveA();
		return 0;
	}
	if(B)
	{
		solveB();
		return 0;
	}
	if(n<=100)
	{
		dfs(0,1);
		cout<<ans;
		return 0;
	}
	
	return 0;
}