#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q,len[N],f[N],e[N];
string s1[N],s2[N],t1,t2;
int jdz(int a){
	if(a>0) return a;
	else return -a;
}
void gs(){
	cin>>t1>>t2;
	int ans = 0;
	int ln = t1.length();
	if(ln!=t2.length()){
		cout<<0<<'\n';
		return;
	} 
	int ft = 0,et = 0;
	for(int i = 0;i<ln;i++){
		if(t1[i]!=t2[i]){
			ft = i;
			break;
		} 
	}
	et = ft;
	for(int i = ft;i<ln;i++){
		if(t1[i]!=t2[i]){
			et = i;
		} 
	}
	for(int i = 1;i<=n;i++){
		bool fg = 0;
		if(len[i]!=et-ft+1||ln<s1[i].length()) continue;
		int l = s1[i].length();
		for(int j = 0;j<l;j++){
			if(t1[ft+j-f[i]]!=s1[i][j]||t2[ft+j-f[i]]!=s2[i][j]){
				fg = 1;
				break;
			}
		} 
		if(fg) continue;
		ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i] = s1[i].length();
		for(int j = 0;j<len[i];j++){
			if(s1[i][j]!=s2[i][j]){
				f[i] = j;
				break;
			}
		} 
		e[i] = f[i];
		for(int j = f[i];j<len[i];j++){
			if(s1[i][j]!=s2[i][j]){
				e[i] = j;
			}
		} 
		len[i] = e[i]-f[i]+1;
	}
	while(q--){
		gs();
	}
	return 0;
} 
