#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string x,y;
string a[200005],b[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		int cnt(0);
		for(int i=1;i<=n;++i){
			int t=x.find(a[i]),f(0);
			string k=x;
			while(t!=-1){
				string p=x.substr(0,t)+b[i]+x.substr(a[i].size()+t);
				if(p==y) f=1;
				k[t]='#';
				t=k.find(a[i]);
			}
			if(f) cnt++;
		}
		cout<<cnt<<'\n';
	}
}
