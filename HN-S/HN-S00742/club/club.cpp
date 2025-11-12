#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
const int D = 5;
bitset <N> vis;
int T,n,ans;
int a[D];
int cnt[D];
priority_queue < pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > Q[D];
void solve(){
	cin>>n; ans=0;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
		while(Q[i].empty()!=true) Q[i].pop();
	}for(int i=1;i<=n;i++) vis[i]=false;
	for(int i=1;i<=n;i++){
		int maxn=0,lk=1;
		for(int j=1;j<=3;j++){
			cin>>a[j];
			if(a[j]>maxn) maxn=a[j],lk=j;
		}cnt[lk]++; ans+=maxn;
		for(int j=1;j<=3;j++) if(j!=lk) Q[lk].push({maxn-a[j],i});
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<=n/2) continue;
		int tmp=cnt[i]-n/2;
		while(tmp){
			if(vis[Q[i].top().second]){Q[i].pop();continue;}
			vis[Q[i].top().second]=true; tmp--;
			ans-=Q[i].top().first; Q[i].pop();
		}
	}cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
Ren5Jie4Di4Ling5%

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

void Add(int lk,int r,int val){
	if(cnt[r]<n/2){
		ans+=val; cnt[r]++;
		vis[lk]=true;
		for(int i=1;i<=3;i++)
			if(val>a[lk][i])
				Q[r].push({lk,i,val-a[lk][i]});
	}else if(val>Q[r].top().v){
		node dq=Q[r].top();
		Add(dq.p,dq.t,a[dq.p][dq.t]);
		ans+=(val-(a[dq.p][dq.t]+Q[r].top().v));
		Q[r].pop();
	}
}
void solve(){
	cin>>n; ans=l=0;
	for(int i=1;i<=3;i++) {
		cnt[i]=0;
		while(Q[i].empty()!=true) Q[i].pop();
	}
	for(int i=1;i<=n;i++) vis[i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
		}
	}sort(V+1,V+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(vis[V[i].p]) continue;
		Add(V[i].p,V[i].t,V[i].v);
	}cout<<ans<<'\n'; 
}
signed main(){
//	freopen("club2.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
*/
