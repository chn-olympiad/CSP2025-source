#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int> pii;
#define fr first
#define sc second
int T,n;
struct Node{pii mx,se;}nd[N];
pii b,bb,bbb;
priority_queue<pii,vector<pii>,greater<pii>>q[4];
void solve()
{
	cin>>n;
	for(int i=1,a,aa,aaa;i<=n;i++)
	{
		cin>>a>>aa>>aaa;
		b={a,1},
		bb={aa,2},
		bbb={aaa,3};
		if(b<bb)swap(b,bb);
		if(bb<bbb)swap(bb,bbb);
		if(b<bb)swap(b,bb);
		nd[i]={b,bb};
	}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		int fav=nd[i].mx.sc,sz=q[fav].size();
		if(sz<n/2){q[fav].emplace(nd[i].mx.fr-nd[i].se.fr,nd[i].se.sc),res+=nd[i].mx.fr;continue;}
		int tp=q[fav].top().fr,nxt=q[fav].top().fr;
		if(tp<=nd[i].mx.fr)q[fav].pop(),q[nxt].emplace(tp,nxt),res+=(long long)nd[i].mx.fr-tp,q[fav].emplace(nd[i].mx.fr-nd[i].se.fr,nd[i].se.sc);
		else q[nd[i].se.sc].emplace(nd[i].mx.fr-nd[i].se.fr,nd[i].se.sc),res+=nd[i].se.fr;
	}
	for(int i=1;i<=3;i++)while(q[i].size())q[i].pop();
	cout<<res<<"\n";
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;while(T--)solve();
}
//神人RE我服了 
