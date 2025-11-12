#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
int del[N],sl[N],sr[N];
int n,q;
int jud(int pos,int num){
	for(int i=pos;i<=pos+s1[num].size()-1;i++){
		//if(pos+s1[num].size()-1<) return 0;
		if(i>=t1.size()) return 0;
		int j=i-pos;
		if(t1[i]!=s1[num][j]) return 0;
		if(t2[i]!=s2[num][j]) return 0;
	}
	return 1;
}
void solve(){
	if(t1.size()!=t2.size()){
		cout<<0<<endl;
		return ;
	}
	int l=0,r=t1.size()-1;
	for(int i=0;i<t1.size();i++){
		if(t1[i]!=t2[i]&&l==0){
			l=i;
			break;
		}
	}
	for(int i=t1.size()-1;i>=0;i--){
		if(t1[i]!=t2[i]&&r==t1.size()-1){
			r=i;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s1[i].size()<(r-l+1)) continue;
		if(s1[i].size()>t1.size()) continue;
		int st=r-s1[i].size()+1,ed=t1.size()-s1[i].size()+1;
		st=max(st,0);ed=min(l,ed);
		for(int j=st;j<=ed;j++) {
			if(jud(j,i)) ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
void preB(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				sl[i]=j;
				break;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				sr[i]=j;
				break;
			}
		}
		del[i]=sl[i]-sr[i];
	}
}
void B(){
	if(t1.size()!=t2.size()){
		cout<<0<<endl;
		return ;
	}
	int l=0,r=0;
	for(int i=0;i<t1.size();i++){
		if(t1[i]=='b'){
			l=i;
			break;
		}
	}
	for(int i=0;i<t2.size();i++){
		if(t2[i]=='b'){
			r=i;
			break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(l-r!=del[i]) continue ;
		if(l-sl[i]<0) continue;
		if(l+(s1[i].size()-sl[i])>=t1.size()) continue;
		if(r-sr[i]<0) continue;
		if(r+(s2[i].size()-sr[i])>=t2.size()) continue;
		ans++; 
	}
	cout<<ans<<endl;
	return ;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b'){
				flag=0;
				break;
			}
			if(s2[i][j]!='a'&&s2[i][j]!='b'){
				flag=0;
				break;
			}
		}
	}
	if(flag) preB();
	while(q--){
		cin>>t1;
		cin>>t2;
		if(flag) B();
		else solve();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb */

