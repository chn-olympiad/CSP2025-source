#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<string,string> mp;
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while (m--){
		int ans=0;
		string s,t;
		cin>>s>>t;
		if (s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		string a,b,c;
		for (int i=0;i<s.size();i++){
			c="";
			for (int j=s.size()-1;j>=i;j--){
				b="";
				for (int k=i;k<=j;k++){
					b+=s[k];
				}
				b=mp[b];
				b=a+b+c;
				if (b==t){
					ans++;
				} 
				c=s[j]+c;
			}
			a+=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

