#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
int n;
int a[5005];
ll dp[10005];
ll cg[10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int maxn=0;
	//dp[0]=1;
	//for(int i=a[1]-1;i>=0;i--)cg[i]++;
	//for(int i=a[2]-1;i>=0;i--)cg[i]++:
	//for(int i=a[1]+a[2]-1;i>=0;i--) cg[i]++;
	//maxn=a[2];
	//cg[0]=1;
	ll total=1;
	for(int i=1;i<=n;i++){
		ll num=1;
		for(int j=1;j<=i;j++){
			num*=(n-j+1);
			num/=j;
			num%=mod;
			
		}
		total+=num;
		total%=mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		
		maxn=max(maxn,a[i]*2);
		//int tmp=a[i-1];
		for(int j=1;j<=maxn;j++){
			if(j>=a[i])
				dp[j]=cg[j]+cg[j-a[i]]+1,dp[j]%=mod;
			else
				dp[j]=cg[j]+1;
		}
		for(int j=1;j<=maxn;j++){
			cg[j]=dp[j];
		}
		
		//cout<<maxn<<" " <<dp[maxn]<<endl;
		//for(int j=1;j<=maxn;j++)cout<<dp[j]<<" ";
		cout<<endl;
		ans+=dp[maxn];
		ans%=mod;
	}
	if(total-ans<0) cout<<total+mod-ans;
	else cout<<total-ans;
	return 0;
}
