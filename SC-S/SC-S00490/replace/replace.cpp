#include<bits/stdc++.h>
using namespace std;
map <string,map<string,int> > mp;
int n,q;
string s1,s2,s,ss;
bool check(int be){
	for(int i=be;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			return false; 
		}
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1][s2]++;
	}
	while(q--){
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()==1 && s2.size()==1){
			cout<<mp[s1][s2]<<"\n";
			continue;
		}
		for(int l=0;l<s1.size();l++){
			s="";
			ss="";
			for(int r=l;r<s1.size();r++){
				s+=s1[r];
				ss+=s2[r];
				if(check(r+1)){
					ans+=mp[s][ss];
				}
			}
		}
		cout<<ans;
	}
	return 0;
}