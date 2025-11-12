#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int p=998244353;
int n;
int a[5005];
//int dp[5005][5005];
int ans=0;
int mp=0;
long long ksm(long long a,long long b)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1){
			ans*=a;
			ans=ans%p;
		}
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int p,int sum,int f,int now)
{
	
	if(p>=3)
	{
		if(sum>2*a[f]){
			ans++;	
		} 
	}
	if(now>n)return;
	if(f==0)
	{
		dfs(p+1,sum+a[now],now,now+1);
	}
	else dfs(p+1,sum+a[now],f,now+1);
	if(p>=3&&sum>2*a[f])ans--;
	dfs(p,sum,f,now+1);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool sta=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)sta=0;
	}
	sort(a+1,a+n+1,cmp);
	if(sta||a[1]<a[n]+a[n-1])
	{
		cout<<((ksm(2,n)-1-n-(n*(n-1))/2)%p+p)%p;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}