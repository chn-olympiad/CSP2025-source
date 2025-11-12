#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int inf=0x3f3f3f3f;
constexpr int N=1e5+5;
int a[N][5];
namespace SSS {
	priority_queue<pair<ll,int>>q2;//val pos
	priority_queue<pair<ll,pair<int,int>>>q3,q1,q4;
	int t[5];
	int to[N];
	void work() {
	//	debug<<"---------\n";
		int n;cin>>n;
		ll ans=0;
		fo(i,1,n) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q2.push(mp(a[i][2]-a[i][1],i));
			ans+=a[i][1];
			to[i]=1;
		}
		int L=n/2;
		fo(i,1,L) {
			ll val=q2.top().fi;int p=q2.top().se;q2.pop();
			ans+=val;
	//		debug<<val<<endl;
	//		debug<<p<<' '<<val<<endl;
			q3.push(mp(a[p][3]-a[p][2],mp(p,2)));
			to[p]=2;
		}
	//	fo(i,1,n) cerr<<to[i]<<" \n"[i==n];
		fo(i,1,L) {
			int p=q2.top().se;q2.pop();
			q3.push(mp(a[p][3]-a[p][1],mp(p,1)));
		}
	//	assert(q2.size()==0);
	//	assert(q3.size()==n);
		t[1]=L;t[2]=L;t[3]=0;
		while(t[3]<L&&!q3.empty()) {
			ll val=q3.top().fi;int p=q3.top().se.fi,m=q3.top().se.se;
			if(val<=0) break;
			q3.pop();
			if(t[m]==0) continue;
	//		debug<<p<<' '<<m<<endl;
	//		debug<<p<<' '<<m<<' '<<' '<<val<<endl;
			ans+=val;
			t[m]--;t[3]++;
			to[p]=3;
		}
		fo(i,1,n) if(to[i]!=1) {
			q1.push(mp(a[i][1]-a[i][to[i]],mp(i,to[i])));
		}
	//	debug<<q1.size()<<' '<<t[1]<<endl;
		while(t[1]<L&&!q1.empty()) {
			ll val=q1.top().fi;int p=q1.top().se.fi,m=q1.top().se.se;q1.pop();
			if(val<=0) break;
			if(t[m]==0) continue;
	//		debug<<p<<' '<<m<<endl;
			ans+=val;
			t[m]--;t[1]++;
			to[p]=1;
		}
		//q1 jie q2 yong
		while(!q1.empty()) q1.pop();
		fo(i,1,n) if(to[i]!=2) {
			q1.push(mp(a[i][2]-a[i][to[i]],mp(i,to[i])));
		}
		while(t[2]<L&&!q1.empty()) {
			ll val=q1.top().fi;int p=q1.top().se.fi,m=q1.top().se.se;q1.pop();
			if(val<=0) break;
			if(t[m]==0) continue;
	//		debug<<p<<' '<<m<<endl;
			ans+=val;
			t[m]--;t[2]++;
			to[p]=2;
		}
	//	fo(i,1,n) cerr<<to[i]<<" \n"[i==n];
	//	assert(t[1]>=0&&t[1]<=L);
	//	assert(t[2]>=0&&t[2]<=L);
	//	assert(t[3]>=0&&t[3]<=L);
	//	ans=0;
	//	fo(i,1,n) ans+=a[i][to[i]];
		//nooooooooooooooooooooooooooooo
	//	debug<<L<<' '<<t[1]<<' '<<t[2]<<' '<<t[3]<<endl;
		cout<<ans<<endl;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		while(!q4.empty()) q4.pop();
		fo(i,1,n) to[i]=a[i][1]=a[i][2]=a[i][3]=0;
		t[1]=t[2]=t[3]=0;
		//clear
	}
}
int n;
void solve1() {
	ll ans=0;
	priority_queue<ll>q;
	fo(i,1,n) q.push(a[i][1]);
	fo(i,1,n/2) {
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<endl;
}
void solve2() {
	priority_queue<ll>q;
	ll ans=0;
	fo(i,1,n) {
		q.push(a[i][2]-a[i][1]);
		ans+=a[i][1];
	}
	fo(i,1,n/2) {
		ans+=q.top();q.pop();
	}
	cout<<ans<<endl;
}
int to[N],t[5];
ll ans=0;
void dfs(int p) {
	if(t[1]>n/2||t[2]>n/2||t[3]>n/2) return;
//	debug<<t[1]<<' '<<t[2]<<' '<<t[3]<<endl;
	if(p>n) {
//		debug<<1<<endl;
		ll res=0;
		fo(i,1,n) res+=a[i][to[i]];
//		debug<<t[1]<<' '<<t[2]<<' '<<t[3]<<' '<<res<<endl;
		ans=max(ans,res);
		return;
	}
	to[p]=1;
	t[1]++;
	dfs(p+1);
	t[1]--;
	to[p]=2;
	t[2]++;
	dfs(p+1);
	t[2]--;
	to[p]=3;
	t[3]++;
	dfs(p+1);
	t[3]--;
}
void work() {
	cin>>n;
	int A=0,B=0;
	fo(i,1,n) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		A|=a[i][2];
		A|=a[i][3];
		B|=a[i][3];
	}
	if(!A) solve1();
	else if(!B) solve2();
	else {
		if(n>10) SSS::work();
		else {
			ans=0;
			dfs(1);
			cout<<ans<<endl;
		}
	}
	fo(i,1,n) to[i]=a[i][1]=a[i][2]=a[i][3]=0;
	//clear
}
int main() {
	fin("club.in");fout("club.out");
	ios::sync_with_stdio(0);cin.tie(0);
	int tt;cin>>tt;
	while(tt--) work();
	return 0;
}
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <assert.h>
//#define fin(f) freopen(f,"r",stdin)
//#define fout(f) freopen(f,"w",stdout)
//#define fo(i,l,r) for(int i=(l);i<=(r);i++)
//#define of(i,r,l) for(int i=(r);i>=(l);i--)
//#define debug cerr<<"["<<__LINE__<<"] "
//#define pb push_back
//#define mp make_pair
//#define fi first
//#define se second
//#define endl '\n'
//using namespace std;
//typedef long long ll;
//constexpr int inf=0x3f3f3f3f;
//constexpr int N=1e5+5;
//int a[N][5];
//priority_queue<pair<ll,int>>q2;//val pos
//priority_queue<pair<ll,pair<int,int>>>q3,q1,q4;
//int t[5];
//int to[N];
//void work() {
//	debug<<"---------\n";
//	int n;cin>>n;
//	ll ans=0;
//	fo(i,1,n) {
//		cin>>a[i][1]>>a[i][2]>>a[i][3];
//		q2.push(mp(a[i][2]-a[i][1],i));
//		ans+=a[i][1];
//		to[i]=1;
//	}
//	int L=n/2;
//	fo(i,1,L) {
//		ll val=q2.top().fi;int p=q2.top().se;q2.pop();
//		ans+=val;
////		debug<<val<<endl;
//		debug<<p<<' '<<val<<endl;
//		q3.push(mp(a[p][3]-a[p][2],mp(p,2)));
//		to[p]=2;
//	}
//	fo(i,1,n) cerr<<to[i]<<" \n"[i==n];
//	fo(i,1,L) {
//		int p=q2.top().se;q2.pop();
//		q3.push(mp(a[p][3]-a[p][1],mp(p,1)));
//	}
//	assert(q2.size()==0);
//	assert(q3.size()==n);
//	t[1]=L;t[2]=L;t[3]=0;
//	while(t[3]<L&&!q3.empty()) {
//		ll val=q3.top().fi;int p=q3.top().se.fi,m=q3.top().se.se;
//		if(val<=0) break;
//		q3.pop();
//		if(t[m]==0) continue;
////		debug<<p<<' '<<m<<endl;
//		debug<<p<<' '<<m<<' '<<' '<<val<<endl;
//		ans+=val;
//		t[m]--;t[3]++;
//		to[p]=3;
//	}
//	fo(i,1,n) if(to[i]!=1) {
//		q1.push(mp(a[i][1]-a[i][to[i]],mp(i,to[i])));
//	}
////	debug<<q1.size()<<' '<<t[1]<<endl;
//	while(t[1]<L&&!q1.empty()) {
//		ll val=q1.top().fi;int p=q1.top().se.fi,m=q1.top().se.se;q1.pop();
//		if(val<=0) break;
//		if(t[m]==0) continue;
////		debug<<p<<' '<<m<<endl;
//		ans+=val;
//		t[m]--;t[1]++;
//		to[p]=1;
//	}
//	//q1 jie q2 yong
//	while(!q1.empty()) q1.pop();
//	fo(i,1,n) if(to[i]!=2) {
//		q1.push(mp(a[i][2]-a[i][to[i]],mp(i,to[i])));
//	}
//	while(t[2]<L&&!q1.empty()) {
//		ll val=q1.top().fi;int p=q1.top().se.fi,m=q1.top().se.se;q1.pop();
//		if(val<=0) break;
//		if(t[m]==0) continue;
////		debug<<p<<' '<<m<<endl;
//		ans+=val;
//		t[m]--;t[2]++;
//		to[p]=2;
//	}
//	//q1 jie q3 yong
////	while(!q1.empty()) q1.pop();
////	while(!q2.empty()) q2.pop();
////	fo(i,1,n) if(to[i]==3) {
////		q4.push(mp(a[i][1]-a[i][to[i]],mp(i,to[i])));
////		q4.push(mp(a[i][2]-a[i][to[i]],mp(i,to[i])));
////	}
////	fo(i,1,n) if(to[i]!=3) {
////		q1.push(mp(a[i][3]-a[i][to[i]],mp(i,to[i])));
////	}
////	debug<<q1.size()<<' '<<q4.size()<<endl;
////	while(!q1.empty()&&!q4.empty()) {
////		ll val=q1.top().fi;int p=q1.top().se.fi,m=q1.top().se.se;q1.pop();
////		ll dval=q4.top().fi;int dp=q4.top().se.fi,dm=q4.top().se.se;q4.pop();
//////		debug<<p<<' '<<dp<<endl;
////		if(dval-val<=0) break;
////		if(to[dp]!=3) continue;
////		ans=ans+dval-val;
//////		to[dp]=;//
////	}
////	fo(i,1,n) if(to[i]==3) {
////		int maxx=0;
////		fo(j,1,n) if(to[j]==3) {
////			if(to[i]==3&&to[j]!=3) {
////				if(a[i][to[j]]-a[i][3]+a[j][3]-a[j][to[j]]>0) {
////					ans+=a[i][to[j]]-a[i][3]+a[j][3]-a[j][to[j]];
////					swap(to[i],to[j]);
////				}
////			}
////		}
////	}
//	fo(i,1,n) cerr<<to[i]<<" \n"[i==n];
//	assert(t[1]>=0&&t[1]<=L);
//	assert(t[2]>=0&&t[2]<=L);
//	assert(t[3]>=0&&t[3]<=L);
////	ans=0;
////	fo(i,1,n) ans+=a[i][to[i]];
//	//nooooooooooooooooooooooooooooo
//	debug<<L<<' '<<t[1]<<' '<<t[2]<<' '<<t[3]<<endl;
//	cout<<ans<<endl;
//	while(!q1.empty()) q1.pop();
//	while(!q2.empty()) q2.pop();
//	while(!q3.empty()) q3.pop();
//	while(!q4.empty()) q4.pop();
//	fo(i,1,n) to[i]=a[i][1]=a[i][2]=a[i][3]=0;
//	t[1]=t[2]=t[3]=0;
//	//clear
//}
//int main() {
//	fin("club2.in");fout("club.out");
//	ios::sync_with_stdio(0);cin.tie(0);
//	int tt;cin>>tt;
//	while(tt--) work();
//	return 0;
//}
/*
14:10 jinkaodian
14:15 jinkaochang
14:35 ready,kaiti
15:19 sikaowan
15:48 chonggouT1
17:02 fangqiT1(35pts)
18:05 chonggouT1

17:52 T2 64pts

e:100+64+40+28=232
r:35+64+0+0=99
*/
