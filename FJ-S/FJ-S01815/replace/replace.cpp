#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q,r;
unordered_map<string,string> mp;
string s1,s2,t1,t2;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1>>s2,mp[s1]=s2,r=max(r,(int)s1.size());
	while(q--){
		int ans=0;
		cin>>s1>>s2;
		t1=" ",t1+=s1;t2=" ",t2+=s2;
		if(mp[s1]==s2) ans++;
		for(int i=1;i<t1.size();i++){
			if(t1.substr(1,i-1)!=t2.substr(1,i-1)) continue;
			for(int l=1;i+l<=r;l++){
				if(t1.substr(i+l)!=t2.substr(i+l)) continue;
				if(mp[t1.substr(i,l)]==t2.substr(i,l)) ans++;
			}
		}	
		cout<<ans<<'\n';
	}
	return 0;
} 

