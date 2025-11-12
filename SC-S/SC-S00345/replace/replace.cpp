#include<bits/stdc++.h>//666ccfniyandoubuyanle
#define int long long
using namespace std;
int n,q;
string s1,s2;
map<string,string> m;
int replace(){
	int ans=0;
	if(s1.size()!=s2.size()) return 0;
	for(int i=0;i<s1.size();i++){
		for(int j=1;j<s1.size()-i+1;j++){
			string y=s1.substr(i,j);
			if(m.find(y)!=m.end()){
				string s=s1.substr(0,i)+m[y]+s1.substr(i+j,s1.size()-j+1);
				if(s2==s) ans++;
			}
		}
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<replace()<<'\n';
	}
	return 0;
}