#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
map<string,string> mp;
string s[N][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=s[i][1];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a==b||a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		int sum=0;
		for(int i=0;i<(int)a.size();i++){
			for(int j=i+1;j<(int)a.size();j++){
				string x=a.substr(i,j-i+1);
				string y=mp[x];
				string aa=a.substr(0,i)+y+a.substr(j+1);
				if(aa==b)sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
