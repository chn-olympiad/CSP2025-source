#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void read(ll &x){
	char c=getchar();x=0;
	ll fh=1;
	while('0'>c||c>'9'){
		if(c=='-') fh*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') x=x*10-48+c,c=getchar();
	x*=fh;
}
void write(ll x){
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+5;
ll n,ans,T;
struct NODE{
	ll x,y,z,cz;
}a[N];
priority_queue<ll,vector<ll>,greater<ll> > q[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		read(n);
		ans=0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		for(ll i=1;i<=n;i++){
			read(a[i].x),read(a[i].y),read(a[i].z);
			a[i].cz=max({a[i].x,a[i].y,a[i].z});
			if(a[i].cz==a[i].x)q[1].push(a[i].cz-max(a[i].y,a[i].z));
			if(a[i].cz==a[i].y)q[2].push(a[i].cz-max(a[i].x,a[i].z));
			if(a[i].cz==a[i].z)q[3].push(a[i].cz-max(a[i].y,a[i].x));
			ans+=a[i].cz;
		}
		ll zs=0;
		if((ll)q[1].size()>(n>>1)) zs=1;
		else if((ll)q[2].size()>(n>>1)) zs=2;
		else if((ll)q[3].size()>(n>>1)) zs=3;
		while((ll)q[zs].size()>(n>>1)) {
			ans-=q[zs].top();
			q[zs].pop();
		}
		write(ans);
		putchar('\n');
	}

	return 0;
}