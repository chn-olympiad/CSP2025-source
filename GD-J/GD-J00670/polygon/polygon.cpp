#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,tp;
int a[5010],c[5010],b[5010],r[5010];
bool vis[5010];
ll ans;
ll gys(ll x,ll y) {
	if(x==y) return x;
	else return gys(min(x,y),abs(x-y));
}
void dfs(ll z,int w,int last) {
	if(w>=3) {
		int maxx=-1;
		for(int i=1; i<=w; i++) {
			maxx=max(maxx,r[w]);
		}
		if(maxx*2<z) {
			ans++;
			ans%=MOD;
		}
	}
	if(w>=n) return;
	for(int i=last+1; i<=n; i++) {
		if(!vis[i]) {
			r[++w]=a[i];
			vis[i]=1;
			z+=a[i];
			dfs(z,w,i);
			w--;
			z-=a[i];
			vis[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) {
			tp++;
		}
	}
	if(tp==n) {
		for(int i=3; i<=n; i++) {
			ll fz=1,fm=1,jg;
			for(int j=n,k=i; j>=1,k>=1; j--,k--) {
				fz*=j;
				fm*=k;
				jg=gys(fz,fm);
				fz/=jg;
				fm/=jg;
			}
			cout<<fm<<endl;
			ans+=fz/fm;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
