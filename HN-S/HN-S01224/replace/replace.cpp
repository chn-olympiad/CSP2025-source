#include<bits/stdc++.h>
#define f first
#define se second 
using namespace std;
vector<pair<string,string> >a;
int ans=0;
void update(string &s,int idx,const string &to)
{
	string sub = s.substr(idx);
	s = s+to;
	s = s+sub;
}
int count(const string &s,const string &to)
{
	if(s==to)return ans;
	for(int i=0;i<a.size();i++){
		auto ix=s.find(a[i].f);
		if(ix!=-1){
			s.replace(ix,a[i].se);
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	a.resize(n,make_pair("",""));
	for(auto &s:a){
		cin>>s.f>>s.se;
	}
	while(q--){
		string w;
		cin>>w;
		cout<<count(w)<<endl;
	}
	return 0;
} 
