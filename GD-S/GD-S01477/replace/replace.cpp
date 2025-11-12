#include<bits/stdc++.h>
using namespace std;
bool f(string s,string t){
	if(s.size()>t.size())return 0;
	for(int i=0;i<min(s.size(),t.size());i++)
		if(s[i]!=t[i])return 0;
	return 1;
}
bool ok(pair<pair<string,string>,pair<string,string> >x,pair<pair<string,string>,pair<string,string> >y){
	return f(x.second.first,y.second.first)&&f(x.second.second,y.second.second);
}
string rev(string s){
	reverse(s.begin(),s.end());
	return s;
}
pair<pair<string,string>,pair<string,string> >L(string s,string t){
	if(s==t)return {{"",""},{"",t}};
	int l=0,r=s.size()-1;
	while(s[l]==t[l])l++;
	while(s[r]==t[r])r--;
	return {{s.substr(l,r-l+1),t.substr(l,r-l+1)},{rev(s.substr(0,l)),s.substr(r+1)}};
}
int n,q,ans;
string s,t;
pair<pair<string,string>,pair<string,string> >p[200005],P;
map<pair<string,string>,vector<int> >mp;
vector<int>g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		if(s==t)continue;
		p[i]=L(s,t);
		mp[p[i].first].push_back(i);
//		cout<<p[i].first<<"\n";
	}
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		P=L(s,t);
		g=mp[P.first];
		ans=0; 
		for(int i=0;i<g.size();i++)
			if(ok(p[g[i]],P))ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
//50pts
