#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,m,anss;
string s1,s2,ss1,ss2;
map<string,map<string,bool>> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1][s2]=1;
	}while(q--){
		anss=0;
		cin>>ss1>>ss2;
		m=ss1.size();
		s1=" ",s2=" ";
		s1+=ss1,s2+=ss2;
		l=r=0;
		for(int i=1;i<=m;i++){
			if(l==0 and s1[i]!=s2[i])l=i;
			if(s1[i]!=s2[i])r=i;
		}for(int i=1;i<=l;i++){
			for(int j=r;j<=m;j++){
				anss+=mp[s1.substr(i,j-i+1)][s2.substr(i,j-i+1)];
			}
		}cout<<anss<<'\n';
	}
	return 0;
} 
