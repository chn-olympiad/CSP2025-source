#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	if(n<=1000){
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){cout<<0<<'\n';continue;}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=(int)t1.size()-(int)s1[i].size();j++){
					//cerr<<i<<' '<<j<<'\n';
					string t=t1;
					if(t.substr(j,s1[i].size())!=s1[i]) continue;
					//cerr<<t<<' ';
					t.replace(j,s1[i].size(),s2[i]);
					//cerr<<t<<'\n';
					if(t==t2) {ans++;break;}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
