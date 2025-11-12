#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string> >s;
unordered_map<string,bool>vis;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s_one,s_two;cin>>s_one>>s_two;
		s[s_one].push_back(s_two);
	}
	while(q--){
		string s_one,s_two;cin>>s_one>>s_two;
		if(s.find(s_one)==s.end()){
			cout<<0<<endl;
			continue;
		}
		long long cnt=0;
		for(auto i:s[s_one]){
			vis.clear();
			if(!vis[i] and i==s_two){
				cnt++;
				vis[i]=1; 
			}
			
		}
		cout<<cnt<<endl;
	}
	return 0;
}
