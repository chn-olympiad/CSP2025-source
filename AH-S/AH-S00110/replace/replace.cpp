#include<bits/stdc++.h>
#define QAQ cout<<"QAQ";
using namespace std;
typedef long long ll;

const ll MAXN=2e5+5,inf=1e18,mod=1e9+7;
ll n,q;
string s1[MAXN],s2[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		string tpie;
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll pos=t1.find(s1[i]);
			if(pos==-1){
				continue;
			}
			string x=t1.substr(0,pos);
			string z=t1.substr(pos+s1[i].size(),t1.size()-(s1[i].size()+pos));
			tpie=x+s2[i]+z;
			if(tpie==t2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
