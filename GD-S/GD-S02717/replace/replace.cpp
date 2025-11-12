#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, q;
map<int,vector<pair<int,int> > > m;
string a,b,aa[N],bb[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int k=a.find('b'),g=b.find('b');
		m[g-k].emplace_back((pair<int,int>){k,a.length()-k});
	}
	while(q--){
		cin>>a>>b;
		if(a.length()!=b.length()) {
			cout<<"0\n";
			continue;
		}
		int k=a.find('b'),g=b.find('b');
		int ans=0;
		for(auto i:m[g-k])
			ans+=(i.first<=k&&i.second<=a.length()-k);
		cout<<ans<<'\n';
	}
}
