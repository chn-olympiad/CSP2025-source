#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+3;
int n,q,cnt[MAXN][30][30];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			cnt[i][s1[j]-'a'][s2[j]-'a']++;
		}
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2; 
		if(true){
			cout<<"0\n";
			continue;
		}//ÒÑ·ÅÆú 
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j])need[s1[j]-'a'][s2[j]-'a']++;
		}
	}
	return 0;
}
