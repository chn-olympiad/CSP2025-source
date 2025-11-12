#include<iostream>
#include<algorithm>
using namespace std;
int n;
const long long mod=998244353;
int lon[50005];
int dp[50005];
int qhe[50005];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>lon[i];
		}
		sort(lon+1,lon+n+1);
		if(n<3) cout<<"0";
		else if(lon[1]+lon[2]>lon[3]) cout<<"1";
		else if(lon[1]+lon[2]<=lon[3]) cout<<"0";
		return 0;
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
		{
			cin>>lon[i];
			maxn=max(lon[i],maxn);
		}
		sort(lon+1,lon+n+1);
		for(int i=1;i<=n;i++)
		{
			qhe[i]=qhe[i-1]+lon[i];
		}
if(maxn<=1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		if(lon[i]>=qhe[i-1]) continue;
		for(int j=1;j<=i-2;j++)
		{
			if(qhe[i-1]-lon[j]>lon[i])
			{
				ans++;
			 } 
		}
	}
	return 0;
}