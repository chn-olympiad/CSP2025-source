#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int n,ans,cnt;
int a[5005],add[5005],p[5005];
int mp[5005][5005],ch[5005][5005];

int dfs(int k,int sum){
	if(sum>=add[k]) return 0;
	if(sum<0) return p[k];
	if(k==0){
		if(sum<0) return 1;
		return 0;
	}
	if(ch[k][sum]){
		cnt++;
		return mp[k][sum];
	} 
	ch[k][sum]=1;
	mp[k][sum]=(dfs(k-1,sum)+dfs(k-1,sum-a[k]))%mod;
	return mp[k][sum];
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		add[i]=add[i-1]+a[i];
		p[i]=(p[i-1]<<1)%mod;
		ans=(ans+dfs(i-1,a[i]))%mod;
	}
	cout<<ans;
}
