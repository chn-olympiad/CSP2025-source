#include<bits/stdc++.h>
using namespace std;
long long n,q;
string si[200010],sj[200010];
bool fl[200010];
long long fln;
bool reped(string str,long long x,long long o) {
	if(x+sj[o].length()>str.length()) return 0;
	for(long long i=x;i<x+sj[o].length();i++) if(str[i]!=si[o][i-x]) return 0;
	return 1;
}
string rep(string str,long long x,long long o) {
	string ans=str;
	for(long long i=x;i<x+sj[o].length();i++) ans[i]=sj[o][i-x];
	return ans;
}
long long sov(string str,string tag,long long in) {
	if(str==tag) return 1;
	if(in>=str.length()) return 0;
	if(fln<=0) return 0;
	long long ans=0;
	for(long long i=in;i<str.length();i++) {
		for(long long j=0;j<n;j++) if((!fl[j])&&reped(str,i,j)) {
			fl[j]=1;fln--;
			ans+=sov(rep(str,i,j),tag,i+si[j].length());
			fl[j]=0;fln++;
		}
	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	string ii,ij;
	cin>>n>>q;
	for(long long i=0;i<n;i++) cin>>si[i]>>sj[i];
	for(long long i=0;i<q;i++) {
		cin>>ii>>ij;
		if(ii.length()!=ij.length()) {
			cout<<"0"<<endl;
			continue;
		}
		memset(fl,0,sizeof(fl));fln=n;
		cout<<sov(ii,ij,0)<<endl;
	}
} 
