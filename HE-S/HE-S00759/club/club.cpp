#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
constexpr int MN=1e5+15;
int n,a[MN],b[MN],c[MN],ans;
bool vis[MN];

void init(){
	fill(vis+1,vis+1+n,0);
	fill(a+1,a+1+n,0);
	fill(b+1,b+1+n,0);
	fill(c+1,c+1+n,0);
	ans=0;
}

void solve(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	priority_queue<pir> qa,qb,qc;
	for(int i=1;i<=n;i++){
		int mx=max({a[i],b[i],c[i]});
		if(mx==a[i]){
			if(qa.size()==n/2){
				if(ans+max(b[i],c[i])<qa.top().first+a[i]+ans){
					ans+=qa.top().first+a[i];
					int u=qa.top().second;
					qa.pop();
					qa.push(pir(-a[i]+max(b[i],c[i]),i));
					int mxu=max(b[u],c[u]);
					if(mxu==b[u]){
						qb.push(pir(-b[u]+max(a[u],c[u]),u));
					}else{
						qc.push(pir(-c[u]+max(a[u],b[u]),u));
					} 
				}else{
					ans+=max(b[i],c[i]);
					int mx=max(b[i],c[i]);
					if(mx==b[i]){
						qb.push(pir(-b[i]+max(a[i],c[i]),i));
					}else{
						qc.push(pir(-c[i]+max(a[i],b[i]),i));
					}
				}
			}else qa.push(pir(-a[i]+max(b[i],c[i]),i)),ans+=a[i];
		}else if(mx==b[i]){
			if(qb.size()==n/2){
				if(ans+max(a[i],c[i])<qb.top().first+b[i]+ans){
					ans+=qb.top().first+b[i];
					int u=qb.top().second;
					qb.pop();
					qb.push(pir(-b[i]+max(a[i],c[i]),i));
					int mxu=max(a[u],c[u]);
					if(mxu==a[u]){
						qa.push(pir(-a[u]+max(b[u],c[u]),u));
					}else{
						qc.push(pir(-c[u]+max(a[u],b[u]),u));
					} 
				}else{
					ans+=max(a[i],c[i]);
					int mx=max(a[i],c[i]);
					if(mx==b[i]){
						qa.push(pir(-a[i]+max(b[i],c[i]),i));
					}else{
						qc.push(pir(-c[i]+max(a[i],b[i]),i));
					}
				}
			}else qb.push(pir(-b[i]+max(a[i],c[i]),i)),ans+=b[i];
		}else{
			if(qc.size()==n/2){
				if(ans+max(a[i],b[i])<qc.top().first+c[i]+ans){
					ans+=qc.top().first+c[i];
					int u=qc.top().second;
					qc.pop();
					qc.push(pir(-c[i]+max(b[i],a[i]),i));
					int mxu=max(a[u],b[u]);
					if(mxu==a[u]){
						qa.push(pir(-a[u]+max(b[u],c[u]),u));
					}else{
						qb.push(pir(-b[u]+max(a[u],c[u]),u));
					} 
				}else{
					ans+=max(a[i],b[i]);
					int mx=max(a[i],b[i]);
					if(mx==a[i]){
						qa.push(pir(-a[i]+max(b[i],c[i]),i));
					}else{
						qb.push(pir(-b[i]+max(a[i],c[i]),i));
					}
				}
			}else qc.push(pir(-c[i]+max(a[i],b[i]),i)),ans+=c[i];
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}