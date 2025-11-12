#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll t,n;
ll a[N][10],e[10];
ll ans[10];
struct GO {
	ll sum;
	ll i,j;
	ll zz;
} b[N];
bool cmp(GO x,GO y) {
	return x.sum>y.sum;
}
void qk() {
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(e,0,sizeof(e));
	return ;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(ll i=1; i<=t; i++) {
		qk();
		cin>>n;
		for(ll j=1; j<=n; j++) {
			ll u=-1,v=1e9;
			ll ux,vx;
			for(ll k=1; k<=3; k++) {
				cin>>a[j][k];
				if(a[j][k]>u) {
					u=a[j][k];
					ux=k;
				}
				if(a[j][k]<v) {
					v=a[j][k];
					vx=k;
				}
			}
			ll z;
			if(ux==1&&vx==2) z=3;
			if(ux==1&&vx==3) z=2;
			if(ux==2&&vx==1) z=3;
			if(ux==2&&vx==3) z=1;
			if(ux==3&&vx==1) z=2;
			if(ux==3&&vx==2) z=1;
			b[j].sum=a[j][ux]-a[j][z];
			b[j].i=ux;
			b[j].j=z;
			b[j].zz=j;
		}
		sort(b+1,b+n+1,cmp);
		for(ll j=1; j<=n; j++) {
			ll z;
			if(b[j].i==1&&b[j].j==2) z=3;
			if(b[j].i==1&&b[j].j==3) z=2;
			if(b[j].i==2&&b[j].j==1) z=3;
			if(b[j].i==2&&b[j].j==3) z=1;
			if(b[j].i==3&&b[j].j==1) z=2;
			if(b[j].i==3&&b[j].j==2) z=1;
			if(e[b[j].i]<n/2) {
				e[b[j].i]++;
				ans[i]+=a[b[j].zz][b[j].i];
			} else if(e[b[j].j]<n/2) {
				e[b[j].j]++;
				ans[i]+=a[b[j].zz][b[j].j];
			} else if(e[z]<n/2) {
				e[z]++;
				ans[i]+=a[b[j].zz][z];
			}
		}
	}
	for(ll i=1; i<=t; i++)
		cout<<ans[i]<<endl;
	return 0;
}