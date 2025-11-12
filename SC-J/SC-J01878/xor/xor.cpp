#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],pre[500005],top;
struct LHM{
	ll l,r;
} xp[500005];
bool cmp(LHM a,LHM b){
	return a.r<b.r;
}
map<ll,ll> loc,vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		pre[i]=a[i];
		pre[i]=pre[i]^pre[i-1];
	}
	for(ll i=0;i<=n;i++){
		if(vis[k^pre[i]]){
			xp[++top].l=loc[k^pre[i]]+1;
			xp[top].r=i;
		}
		loc[pre[i]]=i;
		vis[pre[i]]=1;
	}
	sort(xp+1,xp+1+top,cmp);
	ll ans=0,ended=-1;
	for(ll i=1;i<=top;i++){
		if(xp[i].l>ended){
			ended=xp[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}