#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll T,n;
struct Node{
	ll x,y,z;
}a[100010];
ll f[210][110][110];
void solve1(){
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n/2;j++){
			for(ll k=0;k<=n/2;k++) f[i][j][k]=0;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=i;j++){
			for(ll k=0;k+j<=i;k++){
				if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
				if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
				if(j+k<i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
//					printf("%lld %lld %lld : %lld\n",i,j,k,f[i][j][k]);
			}
		}
	}
	ll ans=0;
	for(ll j=0;j<=n/2;j++){
		for(ll k=n/2;k+j>=n/2;k--){
			if(j+k<n/2) continue;
			ans=max(ans,f[n][j][k]);
		}
	}
	printf("%lld\n",ans);	
}
bool cmp(Node x,Node y){
	return x.x<y.x;
}
void solve2(){
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	for(ll i=1;i<=n/2;i++) ans+=a[i].x;
	printf("%lld\n",ans);
}
void solve3(){
	priority_queue<pii,vector<pii>,greater<pii> > p1,p2;
	for(ll i=1;i<=n;i++){
		ll op,val;
		if(a[i].x<a[i].y) op=2,val=a[i].y;
		else op=1,val=a[i].x;
		if(op==1){
			if(p1.size()<n/2) p1.push(make_pair(val,i));
			else{
				ll x1=p1.top().first,x2=a[p1.top().second].y;
				ll x3=val,x4=a[i].y;
				if(x1+x4<x2+x3){
					p2.push(make_pair(x2,p1.top().second));
					p1.pop();
					p1.push(make_pair(val,i));
				}
				else p2.push(make_pair(val,i));
			}
		}
		else{
			if(p2.size()<n/2) p2.push(make_pair(val,i));
			else{
				ll x1=p2.top().first,x2=a[p2.top().second].x;
				ll x3=val,x4=a[i].x;
				if(x1+x4<x2+x3){
					p1.push(make_pair(x2,p2.top().second));
					p2.pop();
					p2.push(make_pair(val,i));
				}
				else p1.push(make_pair(val,i));
			}
		}
	}
	ll ans=0;
	while(!p1.empty()){
		ans+=p1.top().first;
		p1.pop();
	}
	while(!p2.empty()){
		ans+=p2.top().first;
		p2.pop();
	}
	printf("%lld\n",ans);
}
void solve4(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=max(a[i].x,max(a[i].y,a[i].z));
	}
	printf("%lld\n",ans);
}
void solve5(){
	priority_queue<pii,vector<pii>,greater<pii> > p1,p2,p3;
	for(ll i=1;i<=n;i++){
		ll op,val;
		if(a[i].x>=max(a[i].y,a[i].z)) op=1,val=a[i].x;
		else if(a[i].y>=max(a[i].x,a[i].z)) op=2,val=a[i].y;
		else op=3,val=a[i].z;
		if(op==1){
			if(p1.size()<n/2) p1.push(make_pair(val,i));
			else{
				ll num=p1.top().first,id=p1.top().second;
				ll mx,pos;
				if(a[id].y>=a[id].z) mx=a[id].y,pos=2;
				else mx=a[id].z,pos=3;
				ll mxx,poss;
				if(a[i].y>=a[i].z) mxx=a[i].y,poss=2;
				else mxx=a[i].z,poss=3;
				if(num+mxx<=val+mx){
					p1.pop();
					p1.push(make_pair(val,i));
					if(pos==2) p2.push(make_pair(mx,id));
					else p3.push(make_pair(mx,id));
				}
				else if(poss==2) p2.push(make_pair(mxx,i));
				else p3.push(make_pair(mxx,i)); 
			}
		}
		else if(op==2){
			if(p2.size()<n/2) p2.push(make_pair(val,i));
			else{
				ll num=p2.top().first,id=p2.top().second;
				ll mx,pos;
				if(a[id].x>=a[id].z) mx=a[id].x,pos=1;
				else mx=a[id].z,pos=3;
				ll mxx,poss;
				if(a[i].x>=a[i].z) mxx=a[i].x,poss=1;
				else mxx=a[i].z,poss=3;
				if(num+mxx<=val+mx){
					p2.pop();
					p2.push(make_pair(val,i));
					if(pos==1) p1.push(make_pair(mx,id));
					else p3.push(make_pair(mx,id));
				}
				else if(poss==1) p1.push(make_pair(mxx,i));
				else p3.push(make_pair(mxx,i)); 
			}
		}
		else{
			if(p3.size()<n/2) p3.push(make_pair(val,i));
			else{
				ll num=p3.top().first,id=p3.top().second;
				ll mx,pos;
				if(a[id].x>=a[id].y) mx=a[id].x,pos=1;
				else mx=a[id].y,pos=2;
				ll mxx,poss;
				if(a[i].x>=a[i].y) mxx=a[i].x,poss=1;
				else mxx=a[i].y,poss=2;
				if(num+mxx<=val+mx){
					p3.pop();
					p3.push(make_pair(val,i));
					if(pos==1) p1.push(make_pair(mx,id));
					else p2.push(make_pair(mx,id));
				}
				else if(poss==1) p1.push(make_pair(mxx,i));
				else p2.push(make_pair(mxx,i)); 
			}	
		}
	}
	ll ans=0;
	while(!p1.empty()){
		ans+=p1.top().first;
		p1.pop();
	}
	while(!p2.empty()){
		ans+=p2.top().first;
		p2.pop();
	}
	while(!p3.empty()){
		ans+=p3.top().first;
		p3.pop();
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		bool A=true,B=true;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y||a[i].z) A=false;
			if(a[i].z) B=false;
		}
		if(n<=200) solve1();
		else if(A) solve2();
		else if(B) solve3();
		else solve5();
		//我哭了 今年T1咋这难 
	}
	return 0;
} 
