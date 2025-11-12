#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[100001],jc[100001];
bool f;
int cnt;
bool vis[10001];
int zuhe(int x,int y){
	return (jc[x]/(jc[x-y]*jc[y])%mod);
}
void dfs(int step,int x,int sum,int max1,int j){
	if(step==x+1){
		if(sum>max1*2) cnt++;
		cnt%=mod;
	}
	for(int i=j+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,x,sum+i,max(max1,i),i);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1){
			f=1;
		}
	}
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	if(!f){
		int ans=0;
		for(int i=3;i<=n-1;i++){
			int tmp=zuhe(n,i);
			ans+=tmp;
			ans%=mod;
		}
		ans++;
		cout << ans%mod;
	}else{
		for(int len=3;len<=n;len++){
			dfs(0,len,0,0,0);
		}
		cout << cnt;
	}
	return 0;
}