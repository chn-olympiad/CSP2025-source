#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,q;
map<string, string> m;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		m[a] = b;
	}
	
	while(q--){
		ll ans = 0;
		string a,b,t;
		cin>>a>>b;
		for(auto i : m){
			t = a;
			ll x = a.find(i.first);
			ll y = b.find(i.second);
			if(x != -1 && y != -1 && x == y){
				for(int j=x;j<x+i.first.size();++j){
					t[j] = i.second[j-x];
//					cout<<j<<' '<<j-x;
				}
//				cout<<t<<' '<<a<<' '<<b<<'\n';
			}
			
			if(t == b){
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
