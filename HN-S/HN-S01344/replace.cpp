#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N=2e5+9,base=13331,mod=998244353;
ll n,q;
string a[N],b[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n>=10000){
		while(q--)
			cout<<"0\n";
		return 0;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s.size();j++){
				if(j+a[i].size()-1>=s.size()) break;
				if(s.substr(j,a[i].size())!=a[i]) continue;
				string now=s.substr(0,j)+b[i]+s.substr(j+a[i].size());
				if(now==t) ans++;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
/*
think about the details
____________| ___________
|          || |         |
|__________|| |_________|
            |
*/
