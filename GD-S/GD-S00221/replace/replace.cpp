#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
string s[200005][2],t[200005][2];
string x,y;
map<pair<string,string>,int > Mapp;
int solve(string s,string t){
	if(s.size()!=t.size()) return 0;
	int ans=0,R=s.size()-1;
	while(R>=0&&s[R]==t[R]) R--;
	for(int i=0;i<s.size();i++){
		x.clear(),y.clear();
		for(int j=i;j<s.size();j++){
			x+=s[j],y+=t[j];
			if(j>=R) ans+=Mapp[{x,y}];
		}
		if(s[i]!=t[i]) break;
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++) Mapp[{s[i][0],s[i][1]}]++;
	for(int i=1;i<=m;i++)
		printf("%lld\n",solve(t[i][0],t[i][1]));
	return 0;
}
