#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans=INT_MIN;
const ll MAXN=5e5+10;
ll a[MAXN],summ[MAXN],vis[MAXN];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	ll t=a[1];
	summ[1]=t;
	for(ll i=2; i<=n; i++) {
		t=t^a[i];
		summ[i]=t;
	}
	for(ll i=1; i<=n; i++) {
		ll l1=i,r1=l1;
		ll l2=l1,r2=r1;
		ll res=0;
		memset(vis,0,sizeof vis);
		while(l1<=n&&r1<=n) {
			if(abs(summ[r1]-summ[l1-1])==k&&vis[l1]==0&&vis[r1]==0) {
				res++;
				vis[l1]=1;
				vis[r1]=1;
				//cout<<i<<" "<<l1<<" "<<r1<<"\n";
				l1=r1+1;
				r1=l1;	
			}
			r1++;
		}
		while(l2>=1&&r2>=1){
			if(abs(summ[r2]-summ[l2-1])==k&&vis[l2]==0&&vis[r2]==0) {
				res++;
				vis[l2]=1;
				vis[r2]=1;
				//cout<<i<<" "<<l2<<" "<<r2<<"\n";
				r2=l2-1;
				l2=r2;
			}
			l2--;
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}
