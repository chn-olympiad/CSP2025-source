#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[1005],b[1005];
ll ans;

void dfs(ll x,ll y){
	if(x==y){
		ll maxn;
		for(ll i=n;i>=1;i--)if(b[a[i]])maxn=a[i];
		ll sum=0;
		for(ll i=1;i<=n;i++)
			if(b[a[i]])
				sum+=a[i];
		if(sum>maxn*2)ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(b[a[i]]==0){
			b[a[i]]=1;
			dfs(x+1,y);
			b[a[i]]=0;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		memset(b,0,sizeof b);
		dfs(1,i);
	}
	cout<<ans%998%244%353;
	
	return 0;
} 
