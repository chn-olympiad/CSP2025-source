#include<bits/stdc++.h>
#define itn int
#define pb push_back
#define ll long long
#define endl '\n'
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=5e5+5;
int n,k,ans,a[N],s[N];
vector<pair<int,int> > v;
vector<int> l[1<<21];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)
		l[s[i]].pb(i);
	for(int i=1;i<=n;i++){
		int x=s[i-1]^k;
		auto j=lower_bound(l[x].begin(),l[x].end(),i);
		if(j!=l[x].end())
			v.pb(make_pair(*j,-i));
	}
	sort(v.begin(),v.end());
	int ct=0;
	for(auto i:v){
		int l=-i.second;
		int r=i.first;
		if(l>ct){
			ct=r;
			ans++;
		}
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}

