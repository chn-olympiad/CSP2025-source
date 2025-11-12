#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005],ans,x[10005],n;
bool check(ll maxn,ll len){
	if(maxn*2<len) return 1;
	return 0;
}
void dfs(ll cur,ll len,ll maxn,ll cnt){
	if(cur>n){
		if(len!=0&&maxn!=0&&cnt>=3) ans++;
		return ;
	}
	for(ll i=x[cur-1]+1;i<=n;i++){
		if(check(maxn,len+a[i])){
			maxn=max(maxn,a[i]);
			x[cur]=i;
			dfs(cur+1,len+a[i],maxn,cnt+1);
		}
		dfs(cur+1,len,maxn,cnt);
	}
}
int main(void){
	freopen("polygun.in","r",stdin);
	freopen("polygun.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans%998244253;
	return 0;
}
