#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans,f,l,r,u,y,s[5005][5005];
void dfs(int x,int sum,int maxa,int cnt){
	if(cnt+n-x+1<3) return;
	if(x>n){
		if(sum>maxa*2&&cnt>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,sum+a[x],max(maxa,a[x]),cnt+1);
	dfs(x+1,sum,maxa,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f=1;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]){
		f=0;
		break;
	}
	if(f){
		s[0][0]=s[1][0]=s[1][1]=1;
		for(int i=2;i<=n;i++){
			s[i][0]=s[i][i]=1;
			for(int j=1;j<i;j++) s[i][j]=(s[i-1][j-1]+s[i-1][j])%mod;
		}
		for(int i=0;i<=n-3;i++) ans=(ans+s[n][i])%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
