#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define powi2(x) ((x)*(x))
#define pow2i(x) (1<<(x))
//#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+5;
int n,k,a[N],sum[N],ans;
unordered_map<int,priority_queue<int> > m;
vector<pii> v;
start_code
openfile(xor);
cin>>n>>k;
for (int i = 1;i <= n;i ++) cin>>a[i],sum[i] = sum[i-1]^a[i];
m[0].push(0);
for (int i = 1;i <= n;i ++)
{
	auto p = m.find(sum[i]^k);
	if (p != m.end()) v.push_back({p->second.top()+1,i});
	m[sum[i]].push(i);
}
//for (auto i:v) cout<<i.first<<' '<<i.second<<'\n';
sort(v.begin(),v.end(),[](const pii&x,const pii&y){return x.second<y.second;});
for (int i = 0,las = 0;i < (int)v.size();i ++)
	if (v[i].first > las)
		ans ++,las = v[i].second;
cout<<ans;
stop_code
