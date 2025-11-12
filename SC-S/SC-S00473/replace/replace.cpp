#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll n,q;
map<string,string> mp;
string s[N];

void read(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s[i]=x;
		mp[x]=y;
	}
}
void solve(){
	while(q--){
		string t1,t2;
		ll ans=0;
		cin>>t1>>t2;
		string x="";
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				if(i+s[j].size()>t1.size()) continue;
				string k=t1.substr(i,s[j].size());
				if(k==s[j]){
					string p=t1.substr(i+s[j].size());;
					if(x==t2.substr(0,i)&&mp[k]==t2.substr(i,s[j].size())&&p==t2.substr(i+s[j].size()))ans++;
				}
			}
			x+=t1[i];
		}
		cout<<ans<<'\n';
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read();solve();
	return 0;
}