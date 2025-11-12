#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;++i){
		cin>>t[i].first>>t[i].second;
	}
	
	return 0;
}

