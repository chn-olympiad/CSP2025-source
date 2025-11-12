#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>mp;
bool pd(string s1,int& st,string fr){
	int x=s1.find(fr,st);
	return x!=-1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(auto x:mp){
			string fr=x.first,to=x.second;
			if(s2.find(to)==-1) continue;
			int st=0;
			while(pd(s1,st,fr)){
				string tmp=s1;
				tmp.replace(st,fr.size(),to);
				ans+=(tmp==s2);
				st++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
replace±©Á¦°æ 

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


Ô¸´ËÐÐ,ÖÕµÖÈºÐÇ ÈªÃÅÓÀ´æ
I love ldyy 
icebird_ldyy code
*/
