#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int len[200005];
struct node{
	string da,db,l,r;
};
node slv(string &s,string &t){
	int le=s.size();
	int ls,rs;
	for(int j=0;j<le;j++){
		if(s[j]!=t[j]){
			ls=j;
			break;
		}
	}
	for(int j=le-1;j>=0;j--){
		if(s[j]!=t[j]){
			rs=j;
			break;
		}
	}
	return (node){s.substr(ls,rs-ls+1),t.substr(ls,rs-ls+1),s.substr(0,ls),t.substr(rs+1,le-rs-1)};
}
map<pair<string,string>,vector<pair<string,string> > >mp;
string qs,qt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i])continue;
		node to=slv(s1[i],s2[i]);
		mp[make_pair(to.da,to.db)].push_back(make_pair(to.l,to.r));
	}
	while(q--){
		cin>>qs>>qt;
		if(qs.size()!=qt.size()){cout<<"0\n";continue;}
		node rt=slv(qs,qt);
		int ans=0;
		int l1=rt.l.size(),l2=rt.r.size();
		vector<pair<string,string> >v=mp[make_pair(rt.da,rt.db)];
		for(int i=0;i<v.size();i++){
			if(v[i].first.size()>l1||v[i].second.size()>l2)continue;
			if(v[i].first==rt.l.substr(l1-v[i].first.size())&&v[i].second==rt.r.substr(0,v[i].second.size()))ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
