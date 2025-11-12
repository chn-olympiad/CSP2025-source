#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=1e3+10;
int n,q;
string s[N][2],t[2];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	rep(i,1,n){
		cin>>s[i][0];
		cin>>s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		ll ans=0;
		for(int l=0;l<(int)t[0].size();++l){
			for(int r=l;r<(int)t[0].size();++r){
				string a=t[0].substr(0,l);
				string b=t[1].substr(0,l);
				if(a!=b)break;
				int n=t[0].size();
				a=t[0].substr(r+1,n-1-r);
				b=t[1].substr(r+1,n-1-r);
				if(a!=b)break;
				a=t[0].substr(l,r-l+1);
				b=t[1].substr(l,r-l+1);
				for(int i=1;i<=n;++i){
					if(s[i][0]==a){
						if(b==s[i][1]){
							++ans;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}

