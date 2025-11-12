#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string> s;
int funcs=0;
void solve(string st,string end){
	funcs=0;
	string t="",x,y;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) continue;
			t="",x="",y="";
			for(int k=0;k<i;k++) x.push_back(st[k]);
			for(int k=i;k<=j;k++) t.push_back(st[k]);
			for(int k=j+1;k<=n;k++) y.push_back(st[k]);
			if(s.find(t)!=s.end()){
				t=s.at(t);
			}
			string temp=x+t+y;
			if(temp==end) funcs++;
		}
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s.insert({s1,s2});
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		solve(a,b);
		cout<<funcs<<endl;
	}
	return 0;
}
