#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,dp[100005][5],x[100005],y[100005],z[100005];
bool cmp(const ll &p,const ll &q){return p>q;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>t;
	for(ll i=1;i<=t;i++){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		ll n,f=1;
		cin>>n;
		for(ll j=1;j<=n;j++){
			cin>>x[j]>>y[j]>>z[j];
			if(y[j]!=0||z[j]!=0)f=0;
		}
		if(f==1){
			ll sum=0;
			sort(x+1,x+n+1,cmp);
			for(ll j=1;j<=n/2;j++)sum+=x[j];
			cout<<sum<<"\n";
		}
	}
	
	return 0;
}
