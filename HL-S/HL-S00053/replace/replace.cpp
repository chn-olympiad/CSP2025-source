#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,q;
vector<pair<string,string> >s;
string t1,t2;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s.push_back({s1,s2});
	}
	while(q--){
		int cnt=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.length();i++){
			string ns;
			for(auto temp:s){
				string s1=temp.first,s2=temp.second;
				if(t1.substr(i,s1.length())==s1){
					string sx,sz,ns;
					sx=t1.substr(0,i);
					sz=t1.substr(i+s1.length(),n-(i+s1.length())+1);
					ns=sx+s2+sz;
					if(ns==t2)cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
