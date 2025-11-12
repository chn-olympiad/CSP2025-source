#include<bits/stdc++.h>
using namespace std;
long long n,q,ans,idx;
string t1[200005],t2[200005],a,b;
void dfs(string s){
	string t="";
	for(int i=0;i<s.size();i++){
		for(int j=1;j<=n;j++){
			if(i+t1[j].size()-1<s.size()){
				if(s.substr(i,t1[j].size())==t1[j]){
					t=s.substr(0,i)+t2[j];
					if(i+t1[j].size()<s.size())t+=s.substr(i+t1[j].size(),s.size()-(i+t1[j].size()));
					if(t==b)ans++;
				}
			}
		}
	} 
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	while(q--){
		cin>>a>>b;
		ans=0;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		dfs(a);
		cout<<ans<<'\n';
	}
	return 0;
} 
