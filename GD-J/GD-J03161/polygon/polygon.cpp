#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5005,mod=998224353;
long long dp[MAXN],n,a[MAXN],ans,maxn;
string last;
map<string,bool>taffy1;
void DFS(long long w,long long maxn,long long sum,string s,long long num)
{
	if(w>n)
	{
		if(num<3)
			return ;
		if(taffy1[s]==true)
			return ;
		taffy1[s]=true;
		if(sum>maxn*2)
			ans++,ans%=mod;
		return ;
	}
	for(int i=w;i<=n;i++)
	{
		DFS(i+1,maxn,sum,s,num);
		s[i-1]+=1;
		DFS(i+1,max(maxn,a[i]),sum+a[i],s,num+1);
		s[i-1]-=1;
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),maxn=max(maxn,a[i]);
	if(n<=10)
	{
		string c;
		for(int i=1;i<=n;i++)
			c=c+'0';
		DFS(1,0,0,c,0);
		printf("%lld",ans);
		return 0;
	}
	if(maxn==1&&n<=500)
	{
		for(int i=3;i<=n;i++)
		{
			long long k=1;
			for(int j=i+1;j<=n;j++)
				k*=j,k%=mod;
			ans+=k;
			ans%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
