#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;

int a[500005],f[500005],n,ans,c[5005][5005];
int mod=998244353;

int C(int x,int y){
	int ans=1;
	for(int i=x;i>=x-y+1;i--)ans*=i,ans%=mod;
	for(int i=1;i<=y;i++)ans/=i;
	return ans;
} 

void dfs(int u){
	if(u>n){
		int cnt=0,Max=-1,sum=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				cnt++;
				sum+=a[i];
				Max=max(Max,a[i]);
			}
		}
		if(cnt>=3&&sum-Max>Max){
			ans++;ans%=mod;
		}
		return ;
	}
	f[u]=0;
	dfs(u+1);
	f[u]=1;
	dfs(u+1);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans%mod<<endl;
		return 0;
	}
	if(fl){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				c[i][j]=C(i,j)%mod;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		} 
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
} 
