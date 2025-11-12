#include<bits/stdc++.h>
using namespace std;
const long long MOD=998224353;
long long n,a[5005],sum,ans;
void dfs(int ma,long long s,int m,int x)
{
	if(s>ma*2&&m>=3)ans++,ans=ans%MOD;
	for(int i=x;i<=n;i++)
	{
		dfs(a[i],s+a[i],m+1,i+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]*2>=sum)
		{
			n=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],a[i],1,i+1);
	}
	cout<<ans;
	
	return 0;
} 
