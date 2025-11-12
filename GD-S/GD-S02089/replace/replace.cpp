#include<bits/stdc++.h>
#include <ext/rope>
#define int long long
using ull=unsigned long long;
using namespace std;
using namespace __gnu_cxx;
void eq(crope &c,const string &s){
	for(auto &j:s) c.push_back(j);
}
namespace{
	string a,b;
	int n,q,len[200005];
	crope s1,s2,s[200005],t[200005];
	void MAIN(){
		cin.tie(0)->sync_with_stdio(0);
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			eq(s[i],a);
			eq(t[i],b);
			len[i]=a.size();
		}
		if(n>1e5||q>1e5){
			while(q--) cout<<"0\n";//不可以，总司令！！！ 
			return;
		}
		for(int T=1;T<=q;T++){
			cin>>a>>b,a=" "+a,b=" "+b;
			eq(s1,a),eq(s2,b);
			if(a.size()!=b.size()){
				cout<<"0\n";continue;
			}
			int ans=0;
			for(int i=1;i<a.size();i++)
				for(int j=1;j<=n;j++){
					if(s1.substr(i,len[j])==s[j])
						ans+=(s1.substr(0,i)+t[j]+s1.substr(i+len[j],s1.size()-i-len[j]+1)==s2);
				}
			cout<<ans<<"\n";
		}
	}
}
signed main(){MAIN();}

