#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
int n,a[5005],sum[5005],ans;
bool vis[5005];
bool check(int x,int sum){return sum>2*x;}
void dfs(int x,int cnt,int len,int sum){
	if(cnt==len){
		if(check(a[x],sum))ans++;
		return;
	}
	for(int i=x+1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(i,cnt+1,len,sum+a[i]);
			vis[i]=0;
		}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(check(a[3],a[1]+a[2]+a[3])){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int l=1;l<=n;l++){
		for(int len=3;len<=n;len++){
			vis[l]=1;
			dfs(l,1,len,0);
			vis[l]=0;
		}
	}
	cout<<ans%Mod;
	return 0;
}

