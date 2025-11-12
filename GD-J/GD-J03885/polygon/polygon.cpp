#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
LL n,a[N],res[N],ans;
void dfs(int cur,int cnt,LL maxn,int sum){
	if(cur==n+1){
		if(cnt>=3&&sum>2*maxn){
			ans++;
		}
		return;
	}
	res[cur]=1;
	dfs(cur+1,cnt+1,max(maxn,a[cur]),sum+a[cur]);
	res[cur]=0;
	dfs(cur+1,cnt,maxn,sum);
}
LL C(int n,int m){
	if(n==m){
		return 1;
	}
	long double p=1;
	LL q;
	for(int i=m+1,j=1;i<=n;i++,j++){
		if(j<=n-m){
			p=(p*i/j);
			if((LL)(p-1)>MOD){
				p-=MOD;
			}
			q=p;
		}else{
			q=(q*i)%MOD;
		}
	}
	return q;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}else{
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
