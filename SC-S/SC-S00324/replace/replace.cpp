#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n,Q;
string s[N][2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
	for(string t0,t1;Q;Q--){
		int res=0;
		cin>>t0>>t1;
		for(int j=1;j<=n;++j){
			int k=s[j][0].size();
			for(int i=0;i+k-1<(int)t0.size();++i){
				string v=t0.substr(i,k),ns;
				if(v==s[j][0])v=s[j][1];
				for(int r=0;r<=n;++r){
					if(i<=r&&r<=i+k-1)ns+=v[r-i];
					else ns+=t0[r];
				}
				if(ns==t1)res++;
			}
		}
		cout<<res<<"\n";
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
aaaa bbbb
*/