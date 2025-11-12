#include<bits/stdc++.h>
using namespace std;

map<string,string>mp;
int n,q;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i+=1){
		string a,b;cin>>a>>b;
		mp[a]=b;
	}
	
	while(q--){
		string s1,s2;cin>>s1>>s2;
		int ans = 0;
		for(auto temp:mp){
			int sizefind = s1.find(temp.first);
			string str = s1;
			string temp_ = temp.second;
			if(sizefind!= -1){
				str.replace(sizefind,(int)temp.first.size(),temp_);
			}
			if(str == s2){
				ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}
