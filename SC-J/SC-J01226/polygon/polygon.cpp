#include<bits/stdc++.h>
#define ll long long
using namespace std;int n,a[5020],b=1;ll ans=0;
const ll MOD=998244353;
ll qp(ll x,ll qpow){
	int ans=x;
	while(qpow!=1){
		ans*=ans%=MOD;
		if(qpow%2){ans*=x;(ans+=MOD)%=MOD;}
		qpow/=2;
	}
	return ans;
}
void dfs(int edge,int last,ll num){
	if(edge>=3){/*cout<<"num="<<num<<",last="<<last<<"\n";*/ans+=(num>2*a[last]);ans+=MOD;ans%=MOD;}
	if(edge>=n||last>=n)return;
	for(last++;last<=n;last++)dfs(edge+1,last,num+a[last]);
	return;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i],b=max(b,a[i]);
	if(b==1){
		ans=qp(2,n)-1-n-(n-1)*n/2;//减全都没有，减选一个，减选两个 
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
} 
