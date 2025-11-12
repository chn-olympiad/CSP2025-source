#include<bits/stdc++.h>//wish me a good RP!!!
#define int long long//i love u ljn&Six_Flower
using namespace std;
int n,q;
string s[200020][2],t[200020][2];
//int sa[200020][2],t[200020][2];
int ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i][0]>>t[i][1];
		
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s[i][0]>>s[i][1];
		for(int j=1;j<=n;j++){
			int k=0,st;
			for(int l=0;l<s[i][0].size();l++){
				if(s[i][0][l]==t[j][0][k]){
					k++;
				}else{
					k=0,st=l+1;
				}
				if(k==t[j][0].size()-1){
					k=-1;
					break;
				}
			}
			if(st+t[j][0].size()>s[i][0].size()) k=0;
			bool kk=1;
			if(k==-1){
				for(int l=0;l<s[i][0].size();l++){
					if(st<=l&&l<=st+t[j][0].size()-1){
						if(t[j][1][l-st]!=s[i][1][l]){
							kk=0;
//							cout<<l-st<<' '<<t[j][1][l-st]<<' '<<l<<' '<<s[i][1][l]<<'\n';
							break;
						}
					}else{
						if(s[i][0][l]!=s[i][1][l]){
							kk=0;
//							cout<<j<<i;
//							return 0;
							break;
						}
					}
				}
				if(kk){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
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
