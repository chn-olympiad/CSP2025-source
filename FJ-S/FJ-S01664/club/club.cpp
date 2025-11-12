#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[1000000],b[1000000],c[1000000],sum;
struct cz{
	ll d,id;
}s[100000];
bool cmp(cz x,cz y){
	return x.d>y.d;
}
void dfs(ll ans,ll sa,ll sb,ll sc,ll st){
	if(sa>n/2||sb>n/2||sc>n/2) return;
	if(st>n){
		sum=max(sum,ans);
	}
	else{
		dfs(ans+a[st],sa+1,sb,sc,st+1);
		dfs(ans+b[st],sa,sb+1,sc,st+1);
		dfs(ans+c[st],sa,sb,sc+1,st+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool ib=1,ia=1;
		sum=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) ia=0;
			if(c[i]!=0) ib=0;
		}
		if(ia){
			sort(a+1,a+n+1);
			for(ll i=n;i>=n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<"\n";
		}
		else if(ib){
			for(ll i=1;i<=n;i++){
				s[i]={a[i]-b[i],i};
			}
			sort(s+1,s+n+1,cmp);
			for(ll i=1;i<=n;i++){
				if(i<=n/2) sum+=a[s[i].id];
				else sum+=b[s[i].id];
			}
			cout<<sum<<"\n";
		}
		else{
			dfs(0,0,0,0,1);
			cout<<sum<<"\n";
		}
	}
	return 0;
}

