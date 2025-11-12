#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int cnt1=0,cnt2=0;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]==s2[j]) cnt1++;
			else break;
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]==s2[j]) cnt2++;
			else break;
		}
		s1.erase(0,cnt1);
		s2.erase(0,cnt1);
		s1.erase(s1.size()-cnt2);
		s2.erase(s2.size()-cnt2);
		mp[s1+'|'+s2]++;
	}
	while(q--){
		int cnt1=0,cnt2=0;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]==s2[j]) cnt1++;
			else break;
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]==s2[j]) cnt2++;
			else break;
		}
		s1.erase(0,cnt1);
		s2.erase(0,cnt1);
		s1.erase(s1.size()-cnt2);
		s2.erase(s2.size()-cnt2);
		cout<<mp[s1+'|'+s2]<<"\n";
	}
	return 0;
}