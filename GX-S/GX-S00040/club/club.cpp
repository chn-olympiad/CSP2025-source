#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
auto III=freopen("club.in","r",stdin);
auto OOO=freopen("club.out","w",stdout);
#define LL long long
#define vec vector
#define arr array
#define ALL(x) begin(x), end(x)
#define SIZ(x) signed((x).size())
#define rep(i,l,r) for(int i=l, i##_=r; i<=i##_; i++)
#define per(i,l,r) for(int i=l, i##_=r; i>=i##_; i--)
void tomax(auto& x,auto&& y){if(y>x)x=y;}
void tomin(auto& x,auto&& y){if(y<x)x=y;}
using namespace std; namespace __{

constexpr int N=1e5+5;

void clear(){}

void main(){
	cin.tie(0)->sync_with_stdio(0);
	signed cse; for(cin>>cse; cse--; clear())
[&](){
	int n; cin>>n;
	vec<arr<int,3>> a(n+5);
	LL ans=0;
	priority_queue<int> q[3];
	int cnt[3]{};
	rep(i,1,n){
		rep(j,0,2){
			cin>>a[i][j];
		}
		int p=max_element(ALL(a[i]))-begin(a[i]);
		cnt[p]++;
		ans+=a[i][p];
		int t=0;
		rep(j,0,2) if(j!=p){
			tomax(t,a[i][j]);
		}
		q[p].push(t-a[i][p]);
	}
	rep(j,0,2){
		while(SIZ(q[j])>n/2){
			ans+=q[j].top();
			q[j].pop();
		}
	}
	cout<<ans<<'\n';
}();}}
signed main(){__::main();return 0;}
