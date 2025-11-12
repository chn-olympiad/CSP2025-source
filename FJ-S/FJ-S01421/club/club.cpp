#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000010;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
ll n;
ll a[N][3];
priority_queue<ll> q0,q1,q2,emp;
ll ans;

void solve(){
	n=read();q0=q1=q2=emp;ans=0;
	for(int i=1;i<=n;i++) a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ans+=a[i][0],q0.push(max(a[i][1],a[i][2])-a[i][0]);
		else if(a[i][1]>=a[i][2]) ans+=a[i][1],q1.push(max(a[i][0],a[i][2])-a[i][1]);
		else ans+=a[i][2],q2.push(max(a[i][0],a[i][1])-a[i][2]);
	}
	while(q0.size()>n/2){
		ans+=q0.top();q0.pop();
	}
	while(q1.size()>n/2){
		ans+=q1.top();q1.pop();
	}
	while(q2.size()>n/2){
		ans+=q2.top();q2.pop();
	}
	write(ans),putchar('\n');
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=read();
	while(T--) solve();
	return 0;
}
