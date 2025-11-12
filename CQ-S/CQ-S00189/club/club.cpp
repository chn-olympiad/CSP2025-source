#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
const int N=2e5+5;
int _,n,S,A[N][3],P[N],c[3];
inline void sol() {
	cin>>n,S=0;
	rep(i,0,2) c[i]=0;
	rep(i,1,n) {
		int*v=A[i];
		P[i]=0;
		rep(j,0,2) cin>>v[j],P[i]=(v[j]>v[P[i]]?j:P[i]);
	}
	rep(i,1,n) ++c[P[i]],S+=A[i][P[i]];
	int F=-1;
	rep(i,0,2) if(c[i]>n>>1) F=i;
	if(F<0) {
		cout<<S<<'\n';
		return;
	}
	priority_queue<int>q;
	rep(i,1,n) if(P[i]==F) q.push(max(F==0?0:A[i][0],max(F==1?0:A[i][1],F==2?0:A[i][2]))-A[i][F]);
	while(c[F]>n>>1) --c[F],S+=q.top(),q.pop();
	cout<<S<<'\n'; 
}
signed main() {
	FASTIO;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--) sol();
}
