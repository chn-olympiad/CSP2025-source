#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
//struct node {
//	ll l,r,x;
//} vis[maxn<<2];
ll a[maxn],sum[maxn<<2],Xor[maxn<<2],k,ans,n,vis[maxn];
//ll ls(ll i) {
//	return i<<1;
//}
//ll rs(ll i) {
//	return i<<1|1;
//}
//void up(ll i) {
//	if(vis[ls(i)].x&&(!vis[rs(i)].x)) {
//		Xor[i]=Xor[rs(i)];
//	}
//	if((!vis[ls(i)].x)&&vis[rs(i)].x) {
//		Xor[i]=Xor[ls(i)];
//	}
//	if((!vis[ls(i)].r)&&(!vis[rs(i)].l)) {
//		Xor[i]=(Xor[ls(i)]^Xor[rs(i)]);
//	}
//	if(Xor[i]==k) {
//		ans++;
//		vis[i].l=vis[i].r=1;
//		vis[i].x=vis[i].l&&vis[i].r;
//		return;
//	}
//	if(Xor[i]^Xor[ls(i)]==k&&vis[ls(i)].x==0) {
//		ans++;
//		Xor[i]=Xor[rs(i)];
//		vis[ls(i)].x=1;
//		return;
//	}
//	if(Xor[i]^Xor[rs(i)]==k&&vis[rs(i)].x==0) {
//		ans++;
//		Xor[i]=Xor[ls(i)];
//		vis[rs(i)].x=1;
//		return;
//	}
//	return;
//}
//void build(ll l,ll r,ll i) {
//	if(l==r) {
//		cin>>Xor[i];
//	} else {
//		ll mid=l+r>>1;
//		build(l,mid,ls(i));
//		build(mid+1,r,rs(i));
//		up(i);
//	}
//	return;
//}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)cin>>a[i];
	if(k==0) {
		cout<<n/2;
		return 0;
	}
	if(0<=k&&k<=1) {
		for(int i=1; i<=n; i++) {
			if(vis[i]==true)continue;
			if(a[i]==k) {
				ans++;
				continue;
			}
			if(i!=n&&vis[i]==false&&vis[i]^vis[i+1]==k) {
				ans++;
				vis[i]=vis[i+1]=true;
				continue;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==k) {
			ans++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

