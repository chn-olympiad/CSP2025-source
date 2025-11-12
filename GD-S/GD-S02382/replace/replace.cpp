#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 2e5+5;
int n,q,l,r,ans,p[2][N<<1];
string s[N][2],t[2],k[2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		l=r=0;ans=0;
		for(int i=1;i<=t[0].size();i++){
			if(t[0][i-1]!=t[1][i-1]){
				if(!l)l=i;
				r=i;
			}
		}
		l--;r--;//cerr<<l<<' '<<r<<'\n';
		for(int i=1;i<=n;i++){
			if(s[i][0].size()>t[0].size()||s[i][0].size()<r-l+1)continue;
			k[0]=s[i][0]+"#"+t[0];
			k[1]=s[i][1]+"#"+t[1];
//			cerr<<k[0]<<' '<<k[1]<<'\n';
			for(int j=1;j<k[0].size();j++){
				for(int nw=0;nw<2;nw++){
					int x=p[nw][j-1];
					while(x>0&&k[nw][x]!=k[nw][j])x=p[nw][x-1];
					p[nw][j]=x;
					if(k[nw][x]==k[nw][j])p[nw][j]++;
				}
				if(j>s[i][0].size()){
					if(p[0][j]==s[i][0].size()&&p[1][j]==s[i][0].size()&&j-s[i][0].size()-1>=r&&j-s[i][0].size()-s[i][0].size()<=l){
						ans++;
					}
				}
//				cerr<<j<<' '<<p[0][j]<<' '<<p[1][j]<<'\n';
			}
//			cerr<<i<<' '<<ans<<'\n';
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1 1
xabcx xadex
xabcx xadex
*/
