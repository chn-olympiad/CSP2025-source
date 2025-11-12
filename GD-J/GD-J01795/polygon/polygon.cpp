#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int> > stik;
int stk[5007];
int mi2[5007];
int n;
int mod=998244353;
int solve(int maxx,int dep,int get,int last){
	if(dep==0){
		if(get<=maxx){
			return 0;
		}
		else{
			return mi2[n-last-1];
		}
	}
	if(get>maxx){
		return 0;
	}
	int ans=0;
	for(int x=last+1;x<=n-dep;x++){
		ans+=solve(maxx,dep-1,get+stk[x],x);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
    	cout<<0;
    	return 0;
	}
    mi2[0]=1;
    for(int i=1;i<5007;i++){
    	mi2[i]=mi2[i-1]*2%mod;
	}
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	stik.push(x);
	}
	for(int i=0;i<n;i++){
		int x=stik.top();
		stik.pop();
		stk[i]=x;
	}
	if(n==3){
		if(stk[0]>=stk[1]+stk[2]){
			cout<<0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=2;j<n-i;j++){
			int add=solve(stk[i],j,0,i);
			ans+=add;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
