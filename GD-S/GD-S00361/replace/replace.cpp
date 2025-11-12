#include<bits/stdc++.h>
using namespace std;
int n,q,ans,st,ed;
string s1,s2;
unordered_map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){cout<<"0\n"; continue;}
		ans=0;
		for(int i=0;i<s1.size();i++)
			if(s1[i]!=s2[i]) {st=i; break;}
		for(int i=s1.size()-1;i>=0;i--)
			if(s1[i]!=s2[i]) {ed=i; break;}
		string pre="";
		for(int i=0;i<=st;i++){
			if(i>0)pre=pre+s1[i-1];
			for(int j=ed;j<s1.size();j++){
				string nxt=s1.substr(j+1,s1.size()-j-1);
				string str=s1.substr(i,j-i+1);
				if(pre+mp[str]+nxt == s2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
