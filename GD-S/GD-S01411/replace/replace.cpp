#include<bits/stdc++.h>
using namespace std;
const int kmaxN =2e5+10;
int n,q;
int mal; 
string t[5];string s[5];
map<string,string>m;
map<string,int>num;

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	
	for(int i = 1;i <= n;i++){
		cin>>s[1]>>s[2];
		int l = s[1].length();
		mal = max(mal,l);
		m[s[1]] = s[2];
		num[s[1]]++;
	}
	

	for(int i = 1;i <= q;i++){
		long long ans = 0;
		cin>>t[1]>>t[2];
		if(t[1].size() != t[2].size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i = 0;i < t[1].size();i++){
			string ss = "";
			
			for(int j = 1;i+j-1 < t[1].size();j++){
				if(j > mal) break;
				ss+=t[1][i+j-1];
				if(num[ss]) {
					string ms = m[ss];
					string ns = "";
					for(int k = 0;k < t[1].size();k++){
						
						if(k < i || k > i+j-1){
							ns+= t[1][k];
						} 
						else ns+= ms[k-i];
					}
					if(ns == t[2]){
						ans+=num[ss];
					}
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
