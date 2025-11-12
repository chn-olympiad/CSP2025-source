#include<bits/stdc++.h>
namespace cxk{
	using namespace std;
	#define ll long long
	#define md 998244353
	#define ull unsigned long long
	ll n,q,v1[27],v2[27],zs[200005];
	string s,t;
	map<pair<ll,ull>,pair<ll,ull> >vis;
	pair<ll,ll>ss[200005],tt[200005];
	ll gt1(string s){
		ll ans=0;
		for(auto it:s)ans=(ans*27+v1[it-'a'])%md;
		return ans;
	}
	ull gt2(string s){
		ull ans;
		for(auto it:s)ans=ans*27+v2[it-'a'];
		return ans;
	}
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(nullptr);
		cout.tie(nullptr);
		srand(time(nullptr)); 
		for(int i=0;i<26;i++)v1[i]=v2[i]=i+1;
		random_shuffle(v1+1,v1+26);
		random_shuffle(v2+1,v2+26);
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s>>t;
			zs[i]=s.size();
			ss[i]={gt1(s),gt2(s)};
			tt[i]={gt1(t),gt2(t)};
			vis[ss[i]]=tt[i];
		}
		while(q--){
			cin>>s>>t;
			pair<ll,ull>vs={gt1(s),gt2(s)},vt={gt1(t),gt2(t)};
			ll ans=0;
			for(int i=1;i<=n;i++){
				pair<ll,ull>cl={1,1};
				for(int j=s.size()-zs[i];j>=0;j--){
					if(make_pair(((vs.first-ss[i].first*cl.first%md+md)%md+tt[i].first*cl.first%md)%md,
					vs.second-ss[i].second*cl.second+tt[i].second*cl.second)==vt)ans++;
					cl.first=cl.first*27%md;
					cl.second*=27;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){return cxk::main();}
