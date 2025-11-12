#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
bool f(string s1,string s2,auto it){
	int a=int(s1.find(it.first)),b=int(s2.find(it.second));
	if(a!=-1&&b!=-1&&a==b){
		s1.replace(a,it.second.size(),it.second);
		if(s1==s2){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,q;cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1>>s2;
		for(auto it:m){
			if(f(s1,s2,it)){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}