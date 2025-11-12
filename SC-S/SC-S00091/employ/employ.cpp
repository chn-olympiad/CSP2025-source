#include<bits/stdc++.h>
using namespace std;
const int N=600;
string s;
long long n,m,l[N],d[N],k,ans=0,x[30],mod=998244353;
void dfs(int a,int q)
{
	if(q>=m)
	{
		ans+=x[n-a];
		ans=ans%mod;
		return ;
	}
	if(a==n||n-a<m-q)
		return;
	else
	{
		for(int i=1;i<=n;i+=1)
		{
			if(d[i]==0)
			{
				d[i]=1;
				if(l[i]>(a-q)&&s[a]=='1')
					dfs(a+1,q+1);
				else
					dfs(a+1,q);
				d[i]=0; 
			}
		}
	}
	return ;
}
int tp()
{
	for(int i=1;i<=n;i+=1)
		if(s[i]=='0')
			return 0;
	for(int i=1;i<=n;i+=1)
		if(l[i]==0)
			return 0;
	long long k=1;
	for(int i=1;i<=n;i+=1)
		k=(k*i)%mod;
	return k;
}
int main()
{
	x[0]=1,x[1]=1;
	for(int i=2;i<=20;i+=1)
		x[i]=(x[i-1]*i)%mod;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i+=1)
		cin>>l[i];
	if(m==n)
	{
		ans=tp();	
	}
	else
		dfs(0,0);
	cout<<ans;
	return 0;
}