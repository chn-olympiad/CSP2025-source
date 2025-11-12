#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,ss,t,tt;
map<string,int> p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m; getchar();
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
		t=""; tt="";
		int j,jj;
		for(j=0;j<s.size();j++){
			if(s[j]!=ss[j]) break;
		}
		for(jj=s.size()-1;jj>=0;jj--){
			if(s[jj]!=ss[jj]) break;
		}
		for(int k=j;k<=jj;k++){
			t=t+s[j];
			tt=tt+ss[j];
		}
		p[t+tt]++;
	}
	while(m--){
		cin>>s>>ss;
		t=""; tt="";
		int j,jj;
		for(j=0;j<s.size();j++){
			if(s[j]!=ss[j]) break;
		}
		for(jj=s.size()-1;jj>=0;jj--){
			if(s[jj]!=ss[jj]) break;
		}
		for(int k=j;k<=jj;k++){
			t=t+s[j];
			tt=tt+ss[j];
		}
		if(p.count(t+tt)) cout<<p[t+tt]<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
