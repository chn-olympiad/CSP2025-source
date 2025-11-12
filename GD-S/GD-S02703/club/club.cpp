#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll q,n,A,B,C;
struct sat{ll x,y,z;}a[N];
struct VAL{
	ll x,y,z;
	bool operator < (const VAL &dt) const{
		ll L,R;
		if(A>(n>>1)) L=max(y-x,z-x),R=max(dt.y-dt.x,dt.z-dt.x);
		if(B>(n>>1)) L=max(x-y,z-y),R=max(dt.x-dt.y,dt.z-dt.y);
		if(C>(n>>1)) L=max(x-z,y-z),R=max(dt.x-dt.z,dt.y-dt.z);
		return L<R;
	}
};
priority_queue<VAL,vector<VAL>,less<VAL> >Q;

//=======================================================================
ll get_val(VAL now){
	ll val=-LLONG_MAX;
	if(A>(n>>1)) val=max(now.y-now.x,now.z-now.x);
	if(B>(n>>1)) val=max(now.x-now.y,now.z-now.y);
	if(C>(n>>1)) val=max(now.x-now.z,now.y-now.z);
	return val;
}
//=======================================================================
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin>>q;
	while(q--){
		cin>>n;
		ll ans=0;
		A=B=C=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ll MAX=max(a[i].x,max(a[i].y,a[i].z));
			if(MAX==a[i].x) A++;
			else if(MAX==a[i].y) B++;
			else C++;
			ans+=MAX;
		}ll hal=(n>>1);
		for(int i=1;i<=n;i++){
			ll MAX=max(a[i].x,max(a[i].y,a[i].z));
			if(A>hal&&MAX==a[i].x) Q.push({a[i].x,a[i].y,a[i].z});
			if(B>hal&&MAX==a[i].y) Q.push({a[i].x,a[i].y,a[i].z});
			if(C>hal&&MAX==a[i].z) Q.push({a[i].x,a[i].y,a[i].z});
		}
		while(A>hal||B>hal||C>hal){
			VAL now=Q.top();
			ll val=get_val(now);
			ans+=val;
			if(A>hal) A--;
			else if(B>hal) B--;
			else if(C>hal) C--;
			Q.pop();
		}cout<<ans<<'\n';
		while(!Q.empty()) Q.pop();
	}
	return 0;
}
