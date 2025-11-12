#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
pair<string,string>re[2005];
map<string,bool>mp;
void dfs(string s1,string s2){
	if(mp[s1]) return;
	mp[s1]=1;
	if(s1==s2){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j+re[i].first.size()<s1.size()){
			string t;
			for(int k=0;k<re[i].first.size();k++){
				t+=s1[k+j];
			}
			if(t==re[i]){
				t="";
				for(int k=0;k<j;k++){
					t+=s1[k];
				}
				for(int k=j+re[i].first.size();k<s1.size();k++){
					t+=s1[k];
				}
				dfs(t,s2);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>re[i].first>>re[i].second;
	cin>>q;
	while(q--){
		ans=0;
		string s1,s2;cin>>s1>>s2;dfs(s1,s2);
		cout<<ans<<'\n';
	}
	return 0;
}
