#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,len[200200];
string s[200200][2],fi,se,t1,t2;
map<string,bitset<200200> > ls,rs;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		t1=t2="";
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].length();
		int l=0,r=len[i]-1;
		for(;l<len[i];l++) if(s[i][0][l]!=s[i][1][l]) break;
		if(l==len[i]){
			s[i][0]=s[i][1]="";
			len[i]=0;
			continue;
		}
		for(;r>=0;r--)if(s[i][0][r]!=s[i][1][r]) break;
		for(int j=l;j<=r;j++) t1+=s[i][0][j],t2+=s[i][1][j];
		ls[t1][i]=1;
		rs[t2][i]=1;
	}
	while(q--){
		t1=t2="";
		cin>>fi>>se;
		int le=fi.length();
		int l=0,r=le-1;
		for(;l<le;l++) if(fi[l]!=se[l]) break;
		for(;r>=0;r--)if(fi[r]!=se[r]) break;
		for(int j=l;j<=r;j++) t1+=fi[j],t2+=se[j];
		bitset<200200> ans;
		ans=ls[t1]&rs[t2];
		cout<<ans.count()<<'\n';
	}
	return 0;
}
