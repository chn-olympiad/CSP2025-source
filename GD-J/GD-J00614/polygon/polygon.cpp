#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5050],ans,num[5001][5001];
void dfs(int k,int cnt,int sum,int mx,bool flag){
	if(sum>2*mx&&cnt>=3&&flag){
		flag=0;
		ans=((ans+1)%mod+mod)%mod;
	}
	if(k>n) return;
	dfs(k+1,cnt,sum,mx,flag);
	dfs(k+1,cnt+1,sum+a[k],max(a[k],mx),1);
	return;
}
void solve(){
	cin>>n;
	if(n<=30){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,0,0,0,1);
		cout<<ans;
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]) cnt++;
		}
		num[1][1]=1;
		for(int i=2;i<=cnt;i++){
			for(int j=1;j<=i;j++){
				num[i][j]=((num[i-1][j]+num[i-1][j-1])%mod+mod)%mod;
			}
		}
		for(int i=3;i<=cnt;i++){
			ans=((ans+num[n][i])%mod+mod)%mod;
		}
		cout<<ans;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
}

