#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll n;
ll a[5005];
ll k;
ll ans=0;
void dfs(int now,ll x,ll sum,int p) {
	if(now>p) {
		if(sum>x) ans++;
		return ;
	}
	dfs(now+1,x,sum+a[now],p);
	dfs(now+1,x,sum,p);
	return ; 
}
ll c[5005][5005];
void init() {
	for(int i=0;i<=5000;i++) 
		c[i][i]=1;
	for(int i=1;i<=5000;i++) 
		c[i][1]=i;
	for(int i=1;i<=5000;i++)
		for(int j=2;j<i;j++) {
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=MOD;
		}
	return ;
}
struct Node {
	ll data;
	ll maxn;
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20) {
		for(int i=3;i<=n;i++) {
			k=a[i]*2;
			dfs(1,k,a[i],i-1);
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	else if(a[n]==1) {
		init();
		for(int i=3;i<=n;i++) {
			ans+=c[n][i];
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
	else {
		ll sum[5005];
		for(int i=1;i<=n;i++) 
			sum[i]=a[i],sum[i]+=sum[i-1];
		queue<Node> st[5005];
		st[0].push((Node){0,0});
		for(int i=1;i<=n;i++) 
			while(!st[i-1].empty()) {
				Node u=st[i-1].front();
				st[i-1].pop();
				if(u.data>u.maxn*2) {
					ans++;
					ans%=MOD;
				}
				st[i].push((Node){u.data,u.maxn});
				st[i].push((Node){u.data+a[i],a[i]});
			}
		cout<<ans<<endl;
	}
 	return 0;
}
