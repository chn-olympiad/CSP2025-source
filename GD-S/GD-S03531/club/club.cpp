#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,p,ans,pd[500000];
struct node{
	ll a,b,c;
}dp[100005];
ll dg(ll i,ll cnta,ll cntb,ll cntc){
	if(pd[cnta*11+cntb*103+cntc*3]){
		return pd[cnta*11+cntb*103+cntc*3];
	}
	if(i>n){
		return 0;
	}
	ll maxx=0;
	if((cnta+1)<=n/2){
	//	cout<<dp[i].a<<"A"<<dp[i+1].a<<endl;
		maxx=max(maxx,dg(i+1,cnta+1,cntb,cntc)+dp[i+1].a);
	}
	if((cntb+1)<=n/2){
	//	cout<<dp[i].b<<"B"<<dp[i+1].b<<endl;
		maxx=max(maxx,dg(i+1,cnta,cntb+1,cntc)+dp[i+1].b);
	}
	if((cntc+1)<=n/2){
		//cout<<dp[i].c<<"C"<<dp[i+1].c<<endl;
		maxx=max(maxx,dg(i+1,cnta,cntb,cntc+1)+dp[i+1].c);
	}
	return pd[cnta*11+cntb*103+cntc*3]=maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(pd,0,sizeof(pd));
		n=p=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>dp[i].a>>dp[i].b>>dp[i].c;
		}
		cout<<max(dg(1,1,0,0)+dp[1].a,max(dg(1,0,1,0)+dp[1].b,dg(1,0,0,1)+dp[1].c))<<endl;
	}
}
