#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],pre[N];
long long ans=0,cnt=1;
const int Mod=998244353;
int goal,f[N];
void dfs(int now,int p,int sum){
	if(now>n || p>=goal) return;
	for(int i=now;i<=n;i++){
		dfs(i+1,p,sum);
		if(sum<=a[i]) break;
		cnt*=2;
		dfs(i+1,p+1,sum+a[i]);
		cnt/=2;
	}	
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		for(int i=3;i<=n;i++){
			goal=i;
			dfs(1,0,0);
			ans+=cnt;
			ans%=Mod;
		}
		cout<<ans;
	}
	return 0;
}
