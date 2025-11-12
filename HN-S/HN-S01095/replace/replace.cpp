#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifndef LOCAL
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	return;
}
void fast_read(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return;
}
int n,q;
const int N=2e5+10;
string s[N][2];
void read(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	return;
}
void solve(){
	while(q--){
		string t0,t1;
		cin>>t0>>t1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t0.size()<s[i][0].size()){
				continue;
			}
			bool flag=false;
			for(int j=0;j<=t0.size()-s[i][0].size();j++){
				bool ok=true;
				for(int k=0;k<s[i][0].size();k++){
					if(s[i][0][k]!=t0[j+k]||s[i][1][k]!=t1[j+k]){
						ok=false;
						break;
					}
				}
				if(ok){
					string dat=t0;
					for(int k=j;k<j+s[i][0].size();k++){
						dat[k]=s[i][1][k-j];
					}
					if(dat==t1){
						flag=true;
						break;
					}
				}
			}
			ans+=flag;
		}
		cout<<ans<<'\n';
	}
	return;
}
int main(){
	file_init();
	fast_read();
	read();
	solve();
	return 0;
}
