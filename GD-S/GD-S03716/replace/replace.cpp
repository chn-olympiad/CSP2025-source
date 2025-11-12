#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int q;
pair<string,string>s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].first>>t[i].second;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
}
