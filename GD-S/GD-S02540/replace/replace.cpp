#include<bits/stdc++.h>
using namespace std;
const int N=1e2+1;
int n,q;
string s[N][2],t[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;++i){
		cin>>t[i][0]>>t[i][1];
		int ans=0;
		for(int j=1;j<=n;++j){
			if(t[i][0].size()<s[j][0].size())continue;
			for(int k1=0;k1<=t[i][0].size()-s[j][0].size();++k1){
				if(k1!=0){
					if(t[i][0][k1-1]!=t[i][1][k1-1]){
						break;
					}
				}
				bool flag=true;
				for(int k2=0;k2<s[j][0].size();++k2){
					if(s[j][0][k2]!=t[i][0][k1+k2]){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int k2=0;k2<s[j][1].size();++k2){
						if(s[j][1][k2]!=t[i][1][k1+k2]){
							flag=false;
							break;
						}
					}
					if(flag){
						for(int k2=k1+s[j][1].size();k2<t[i][1].size();++k2){
							if(t[i][0][k2]!=t[i][1][k2]){
								flag=false;
								break;
							}
						}
						if(flag){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
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
