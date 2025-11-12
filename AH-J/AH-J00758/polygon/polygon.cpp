#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
ll n,a[N],cnt;
bool vis[N];
void dfs(ll cur,ll sum,ll maxa){
	if(cur>n) return ;
	vis[cur]=1;
	sum+=a[cur];
	maxa=max(maxa,a[cur]);
	if(sum > 2*maxa) cnt++;
	for(int i=cur+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,sum,maxa);
			vis[i]=0;
		}
	}
	if(cur==n) return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=20){
		for(int i=1;i<=n;i++){
			if(a[i]<1) return 0;
		}
		ll nn=1;
		for(int i=1;i<=n;i++) nn*=i;
		for(int i=3;i<=n;i++){
			ll mm=1,nm=1;
			for(int j=1;j<=i;j++) mm*=j;
			for(int j=1;j<=(n-i);i++) nm*=j;
			cnt+=(nn/(nm*mm));
		}
		cout<<cnt%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,i);
	}
	cout<<cnt%998244353;
	return 0;
}
