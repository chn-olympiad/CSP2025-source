#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int st[N][13],a[N],s[N],n,ans;
/*void init(){
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
		for(int j=1;j<13&&i+(1<<j)<=n;j++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
}*/
int used[N],cnt;
void dfs(int step){
	if(step==n+1){
		if(cnt>=3){
			int sum=0,maxn=0;
			for(int i=1;i<=cnt;i++) sum+=used[i],maxn=max(maxn,used[i]);
			if(sum>2*maxn) ans=(ans+1)%mod;
		}
		return ;
	}
	used[++cnt]=a[step];
	dfs(step+1);
	used[cnt--]=0;
	dfs(step+1);
}
int check(){
	for(int i=1;i<=n;i++)
		if(a[i]>1) return 0;
	return 1;
}
int fpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int x=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()!=-1) {
		cout<<(fpow(2,n)-(1+n+n*(n-1)/2)+mod)%mod;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
