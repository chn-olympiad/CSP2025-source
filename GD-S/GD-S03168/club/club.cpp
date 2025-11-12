#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define V vector
#define pii pair<ll,ll>
#define P priority_queue
typedef long long ll;
const int N=1e5+10;
int T,n,sc[N],th[N],fi[N];
map<pii,int>mp;
unordered_map<int,int>m;
struct node{
	ll a,b,c,id;
}e[N];
inline bool cmp(node& l,node& k){
	return l.a>k.a;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	P<ll>q;
	P<ll,V<pii>,greater<pii>>p[4];
	while(T--){
		cin>>n;
		for(int i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c;
			q.push(a),q.push(b),q.push(c);
			mp[{i,a}]=1,mp[{i,b}]=2,mp[{i,c}]=3;
			e[i].a=q.top(),q.pop();
			e[i].b=q.top(),q.pop();
			e[i].c=q.top(),q.pop();
			e[i].id=i;
		}
		ll ans=0;
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			ll k1=e[i].a-e[i].b;
			ll pid=mp[{e[i].id,e[i].a}];
			if(m[pid]>=n/2){
				auto o=p[pid].top();
				if(k1>o.F){
					p[pid].pop();
					m[mp[{o.S,e[o.S].b}]]++;
					ans=ans-e[o.S].a+e[o.S].b+e[i].a;
					p[pid].push({k1,i});
				}
				else{
					ans+=e[i].b;
					m[mp[{i,e[i].b}]]++;
					p[mp[{i,e[i].b}]].push({k1,i});
				}
			}
			else{
				ans+=e[i].a;
				m[pid]++;
				p[pid].push({k1,i});
			}
		}
		cout<<ans<<endl;
		mp.clear();
		m.clear();
		for(int i=1;i<=3;i++)while(!p[i].empty())p[i].pop();
	}
	return 0;
}
