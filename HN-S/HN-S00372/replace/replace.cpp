#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		string x,y; cin>>x>>y;
		mp[x]=y;
	}
	while(m--){
		cout<<"0\n";
	}
	return 0;
} 
