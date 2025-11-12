#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q,ans;
map<string,string> mp;
string s1[N],s2[N];
void dfs(string s,string targ,int step){
	if(s==targ){
		ans++;
		return;
	}
	if(step) return;
	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size();j++){
			string x=s.substr(i,j-i+1);
			if(mp[x]!=""){
				string x1=s.substr(0,i),x2=s.substr(j+1,n-j);
				string xx=x1+mp[x]+x2;
				dfs(xx,targ,1);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		dfs(t1,t2,0);
		cout<<ans<<endl;
	}
	return 0;
}
