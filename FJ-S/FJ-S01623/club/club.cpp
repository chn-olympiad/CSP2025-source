#include<bits/stdc++.h>
using namespace std;
struct G{
	int asc,bsc,csc;
	bool can_usd=true;
}g[100050];
void st(int n){
	for(int i=1;i<=n;i++){
		g[i].asc=0;
		g[i].bsc=0;
		g[i].csc=0;
		g[i].can_usd=true;
	}
}
bool acmp(G x,G y){
	if( (x.asc >= y.asc) && (x.bsc>y.bsc) && (x.csc>y.csc) ){
		return false;
	}
	else if( (x.asc <= y.asc) && (x.bsc<y.bsc) && (x.csc<y.csc) ){
		return true;
	}
	return x.asc>y.asc;
}
bool bcmp(G x,G y){
	if( (x.bsc>=y.bsc) && (x.bsc-y.bsc<=y.csc-x.csc) ){
		return true;
	}
	else if( (x.bsc<=y.bsc) && (y.bsc-x.bsc<=x.csc-y.csc) ){
		return false;
	}
	return x.bsc>y.bsc;
}
bool ccmp(G x,G y){
	return x.csc>y.csc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n,ans=0;cin>>n;
		int ed;ed=n/2;
		for(int i=1;i<=n;i++){
			cin>>g[i].asc>>g[i].bsc>>g[i].csc;
		}
		
		sort(g+1,g+n+1,acmp);
		for(int i=1;i<=ed;i++){
			if(g[i].can_usd){
				ans+=g[i].asc;
				g[i].can_usd=false;
			}
		}
		sort(g+1,g+n+1,bcmp);
		for(int i=1;i<=ed;i++){
			if(g[i].can_usd){
				ans+=g[i].bsc;
				g[i].can_usd=false;
			}
		}
		sort(g+1,g+n+1,ccmp);
		for(int i=1;i<=ed;i++){
			if(g[i].can_usd){
				ans+=g[i].csc;
				g[i].can_usd=false;
			}
		}
	cout<<ans<<endl;
	st(n);
	}
	return 0;
}
