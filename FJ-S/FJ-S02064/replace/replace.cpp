#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n,q,ans;
gp_hash_table<string,string>s2s;
vector<string>s;

bitset<200001>mod;

void dfs(string now,string end) {
	if(now==end){
		ans++;
		return;
	} 
	for(int i=0;i<n;++i) {
		if(!mod[i]) {
			int index=now.find(s[i]);
			if(index!=string::npos) {
				mod[i]=1;
				string tmp=now;
				for(int j=index,k=0;j<s2s[s[i]].size();++k,++j) tmp[j]=s2s[s[i]][k];
				dfs(tmp,end);
				mod[i]=0; 
			}
		}
	}
}

int main(int argc,char**argv) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;++i) {
		string str1,str2;
		cin>>str1>>str2;
		s2s[str1]=str2;
		s.emplace_back(str1);
	}
	
	for(int i=1;i<=q;++i) {
		string str1,str2;
		cin>>str1>>str2;
		dfs(str1,str2);
		cout<<ans<<'\n';
		ans=0;
		mod=0;
	}
	
	return 0;
}
