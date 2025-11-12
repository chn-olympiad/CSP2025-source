#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,q;
string s1,s2,t1,t2;
unordered_map<string,string>s;
long long ans;
void dfs(string x){
	ans++;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s[s1]=s2;
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		dfs(t1);
		cout<<ans;
	} 
	return 0;
}
