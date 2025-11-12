#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N(1e5+10);
ll n;
struct node{
	ll a,b,c;
}e[N];
struct node1{
	ll x,a,b,c;
};
node1 dp[N][4];
node1 qz(node1 a,node1 b){
	if(a.x>b.x){
		return a;
	}
	return b;
}
void solve(){
	cin>>n;
	for(ll i(1);i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
		node1 now({0,0,0,0});
//		now.a++;
//		now.x+=e[i].a;
		dp[i][1]=now;
//		now.x-=e[i].a;
//		now.a--;
//		now.b++;
//		now.x+=e[i].b;
		dp[i][2]=now;
//		now.x-=e[i].b;
//		now.b--;
//		now.c++;
//		now.x+=e[i].c;
		dp[i][3]=now;
	}
	for(ll i(1);i<=n;i++){
		if(dp[i-1][1].a==n/2){
			dp[i][1]=qz(dp[i][1],dp[i-1][1]);
			if(e[i].a>e[i-1].a){
				dp[i][1].x+=(e[i].a-e[i-1].a);
			}
		}else{
			node1 p(dp[i-1][1]);
			p.a+=1;
			p.x+=e[i].a;
			dp[i][1]=qz(dp[i][1],p);
		}//-
		if(dp[i-1][2].a==n/2){
			dp[i][1]=qz(dp[i][1],dp[i-1][2]);
		}else{
			node1 p(dp[i-1][2]);
			p.a+=1;
			p.x+=e[i].a;
			dp[i][1]=qz(dp[i][1],p);
		}//-
		if(dp[i-1][3].a==n/2){
			dp[i][1]=qz(dp[i][1],dp[i-1][3]);
		}else{
			node1 p(dp[i-1][3]);
			p.a+=1;
			p.x+=e[i].a;
			dp[i][1]=qz(dp[i][1],p);
		}//-
		
		//------------------------------
		
		if(dp[i-1][1].b==n/2){
			dp[i][2]=qz(dp[i][2],dp[i-1][1]);
		}else{
			node1 p(dp[i-1][1]);
			p.b+=1;
			p.x+=e[i].b;
			dp[i][2]=qz(dp[i][2],p);
		}//-
		if(dp[i-1][2].b==n/2){
			dp[i][2]=qz(dp[i][2],dp[i-1][2]);
			if(e[i].b>e[i-1].b){
				dp[i][2].x+=(e[i].b-e[i-1].b);
			}
		}else{
			node1 p(dp[i-1][2]);
			p.b+=1;
			p.x+=e[i].b;
			dp[i][2]=qz(dp[i][2],p);
		}//-
		if(dp[i-1][3].b==n/2){
			dp[i][2]=qz(dp[i][2],dp[i-1][3]);
		}else{
			node1 p(dp[i-1][3]);
			p.b+=1;
			p.x+=e[i].b;
			dp[i][2]=qz(dp[i][2],p);
		}//-
		
		//-----------------------
		
		if(dp[i-1][1].c==n/2){
			dp[i][3]=qz(dp[i][3],dp[i-1][1]);
		}else{
			node1 p(dp[i-1][1]);
			p.c+=1;
			p.x+=e[i].c;
			dp[i][3]=qz(dp[i][3],p);
		}//-
		if(dp[i-1][2].c==n/2){
			dp[i][3]=qz(dp[i][3],dp[i-1][2]);
		}else{
			node1 p(dp[i-1][2]);
			p.c+=1;
			p.x+=e[i].c;
			dp[i][3]=qz(dp[i][3],p);
		}//-
		if(dp[i-1][3].c==n/2){
			dp[i][3]=qz(dp[i][3],dp[i-1][3]);
			if(e[i].c>e[i-1].c){
				dp[i][3].x+=(e[i].c-e[i-1].c);
			}
		}else{
			node1 p(dp[i-1][3]);
			p.c+=1;
			p.x+=e[i].c;
			dp[i][3]=qz(dp[i][3],p);
		}//-
	}
	node1 ans(qz(qz(dp[n][1],dp[n][2]),dp[n][3]));
	cout<<ans.x<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
