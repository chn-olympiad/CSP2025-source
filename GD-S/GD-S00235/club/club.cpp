#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct asd{
	long long A;
	long long B;
	long long C;
	void check(long long &num_a,long long &num_b,long long &num_c)
	{
		long long g1=A,g2=B,g3=C;
		bool flag=true;
		if(A>B&&A>C&&flag)
		{
			if(num_a+1<=n/2) flag=false,num_a++,ans+=A;
			A=-10;
		}
		if(B>A&&B>C&&flag)
		{
			if(num_b+1<=n/2) flag=false,num_b++,ans+=B;
			B=-10;
		}
		if(C>A&&C>B&&flag)
		{
			if(num_c+1<=n/2) flag=false,num_c++,ans+=C;
			C=-10;
		}
		A=g1,B=g2,C=g3;
	}
}a[100501];
long long cmp(asd x,asd y)
{
	if(x.A!=y.A) return x.A>y.A;
	if(x.B!=y.B) return x.B>y.B;
	return x.C>y.C;
}
void dfs(long long k,long long x,long long y,long long z,long long sum)
{
	if(k==n&&sum+max(a[k].A,max(a[k].B,a[k].C))<ans) return;
	if(k>n) ans=max(ans,sum);
	else
	{
		if(x+1<=n/2) dfs(k+1,x+1,y,z,sum+a[k].A);
		if(y+1<=n/2) dfs(k+1,x,y+1,z,sum+a[k].B);
		if(z+1<=n/2) dfs(k+1,x,y,z+1,sum+a[k].C);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	for(cin>>t;t;t--,ans=0)
	{
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i].A>>a[i].B>>a[i].C;
		bool flag1=true,flag2=true;
		for(long long i=1;i<=n;i++) flag1=(flag1&&a[i].B==a[i].C&&a[i].C==0);
		for(long long i=1;i<=n;i++) flag2=(flag2&&a[i].C==0); 
		if(flag1)
		{
			ans=0,sort(a+1,a+1+n,cmp);
			for(long long i=1;i<=n/2;i++) ans+=a[i].A;
		}
		else if(flag2)
		{
			ans=0,sort(a+1,a+1+n,cmp);
			long long dp[100501];
			memset(dp,0,sizeof(dp));
			long long pos=1;
			for(long long i=1;i<=n;i++)
			{
				if(dp[pos+1]+a[i].B<=dp[pos]+a[i].A) dp[pos+1]=dp[pos]+a[i].A,pos++;
				else dp[pos]+=a[i].B;
			}
			ans=dp[pos];
		}
		else if(n<=30) dfs(1,0,0,0,0);
		else
		{
			sort(a+1,a+1+n,cmp);
			long long num_a,num_b,num_c;
			num_a=num_b=num_c=ans=0;
			for(long long i=1;i<=n;i++)
				a[i].check(num_a,num_b,num_c);
			long long maxn=ans;
			num_a=num_b=num_c=ans=0;
			for(long long i=n;i>=1;i--)
				a[i].check(num_a,num_b,num_c);
			ans=max(ans,maxn);
		}
		cout<<ans<<endl;
	}
	return 0;
}
