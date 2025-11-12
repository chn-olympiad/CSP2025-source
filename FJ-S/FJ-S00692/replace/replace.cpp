#include<bits/stdc++.h>
using namespace std;
int n,k;
string p,q;
map<pair<string,string>,int>m;
set<pair<string,string>>st;
struct lmx{
	string s1,s2;
}s[200002];
bool kmp(string u,string v){
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>p>>q;
		s[i]={p,q};
		if(st.count({p,q}))continue;
		st.insert({p,q});
		int l=0,r=p.size()-1;
		while(l<=r&&p[l]==q[l])l++;
		while(l<=r&&p[r]==q[r])r--;
		for(int s=l;s<=r;s++)x+=p[s],y+=q[s];
		if(l<=r)m[{x,y}]++;
	}
	while(k--){
		string x,y;
		cin>>p>>q;
		for(int i=1;i<=n;i++){
			if(kmp(s1,s2)){
				
			}
		}
		if(p.size()!=q.size()){cout<<"0\n";continue;}
		int l=0,r=p.size()-1;
		while(l<=r&&p[l]==q[l])l++;
		while(l<=r&&p[r]==q[r])r--;
		for(int s=l;s<=r;s++)x+=p[s],y+=q[s];
		cout<<m[{x,y}]<<endl;
	}
	return 0;
} 
