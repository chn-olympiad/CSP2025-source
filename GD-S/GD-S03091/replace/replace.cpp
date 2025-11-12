#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
vector<string>a,c;

bool check1(string s,string y){
	for(int i=0;i<s.size();i++){
		if(s[i]!=y[i]) return 0;
	}
	return 1;
}
bool check(string s,string y,string b,int pos,int pos1,int len){
	for(int i=pos,j=0;i<pos+len;i++,j++){
		if(s[i]!=y[j]) return 0;
	}
	for(int i=pos,j=0;i<pos+len;i++,j++){
		s[i]=c[pos1][j];
	}
	return check1(s,b);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,b;
		cin>>s>>b;
		a.push_back(s);
		c.push_back(b);
	}
	while(q--){
		int ans=0;
		string s,b;
		cin>>s>>b;
		if(s.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<s.size();i++){
			for(int j=0;j<a.size();j++){
				if(a[j][0]==s[i]&&check(s,a[j],b,i,j,a[j].size())){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
