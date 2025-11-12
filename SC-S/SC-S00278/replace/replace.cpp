#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[{s1,s2}]++;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int l,r;
		for(l=0;l<s1.size();l++){
			if(s1[l]!=s2[l]) break;
		}
		for(r=s1.size()-1;r>=0;r--){
			if(s1[r]!=s2[r]) break;
		}
		for(int k=0;k<=l;k++){
			for(int h=r;h<s1.size();h++){
				string s3=s1.substr(k,h-k+1);
				string s4=s2.substr(k,h-k+1);
				ans+=mp[{s3,s4}];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}