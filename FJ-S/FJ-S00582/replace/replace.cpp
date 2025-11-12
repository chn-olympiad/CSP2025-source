#include<bits/stdc++.h>
using namespace std;
#define N 2000514
int n,q;
string str[N][2];
map<string,string> mp;
map<string,bool> vis;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
		mp[str[i][0]]=str[i][1];
		vis[str[i][0]]=1;
	}
	while(q--){
		string s1,s2;
		int ans=0;
		cin>>s1>>s2;
		if(q>=3) continue;
		for(int i=0;i<s1.size();i++){
			string s3="";
			for(int j=i;j<s1.size();j++){
				s3+=s1[j];
				if(vis[s3]){
					string x="",z="";
					for(int k=0;k<i;k++) x+=s1[k];
					for(int k=j+1;k<s1.size();k++) z+=s1[k];
					string xu=x+mp[s3]+z;
					if(xu==s2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
