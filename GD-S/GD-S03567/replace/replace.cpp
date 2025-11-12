#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int n,q,ans;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1; i<=n; i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1] = s2;
	}
	for(int i = 1; i<=q; i++){
		ans = 0;
		string s1,s2;
		cin>>s1>>s2;
		int m1=s1.size(),m2=s2.size();
		if(m1 != m2){
			cout<<0<<endl;
			continue;
		}
		s1='#'+s1,s2='#'+s2;
		int l=1,r=1,po=0;
		for(int i = 1; i<=m1; i++){
			if(s1[i] != s2[i] && po == 0) po=1,l=i;
			else if(s1[i] != s2[i]) r=i;
		}
		for(int i = 1; i<=l; i++){
			for(int j = r; j<=m1; j++){
				int len = j-i+1;
				string s = s1.substr(i,len);
				if(mp[s] == s2.substr(i,len)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
