#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define fst first
#define scd second
#define rep(i,s,t) for(ll i=s;i<=t;++i)
#define dep(i,s,t) for(ll i=s;i>=t;--i)
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=1e5+10;

struct _{
	int idx1,idx2,dif;
}a[N];
bool operator<(_ a,_ b){
	return a.dif<b.dif;
}
int cnt[4];
pii t[4];
void __solve(){
	int n;
	cin>>n;
	priority_queue<_> q;
	cnt[1]=cnt[2]=cnt[3]=0;
	ll ans=0;
	rep(i,1,n){
		cin>>t[1].fst>>t[2].fst>>t[3].fst;
		t[1].scd=1;t[2].scd=2;t[3].scd=3;
		sort(t+1,t+4,greater<pii>());
		a[i].idx1=t[1].scd;a[i].idx2=t[2].scd;
		a[i].dif=t[1].fst-t[2].fst;
		ans+=t[1].fst;
	}
	rep(i,1,n) q.push(a[i]);
	while(!q.empty()){
		int idx1,idx2,dif;
		_ a=q.top();q.pop();
		idx1=a.idx1;idx2=a.idx2;dif=a.dif;
//		cerr<<idx1<<' '<<idx2<<endl;
		if(cnt[idx1]<n/2) ++cnt[idx1];
		else{
			++cnt[idx2];
			ans-=dif;
		}
	}
	cout<<ans<<endl;
}
int main(){
#ifndef DEBUG
	file(club)
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--) __solve();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
