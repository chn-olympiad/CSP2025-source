#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7,bs=31;
const int N=2e5+5;

int n,q;
string s[N][2],t[N][2];
int hsh[N][2],ans[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;++i){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=n;++i){
		if(s[i][0]==s[i][1])continue;
		for(int j=1;j<=q;++j){
			if(t[j][0].size()!=t[j][1].size())continue;
			if(t[j][0].size()<s[i][0].size())continue;
			bool can=0;
			//cerr<<s[i][0]<<' '<<t[j][0]<<'\n';
			for(int k=0,l=0;k<t[i][0].length();++k){
				//cerr<<l<<' ';
				
				if(s[i][0][k]==t[j][0][l]&&s[i][1][k]==t[j][1][l])++l;
				else l=0;
				if(l==s[i][0].length()-1){can=1;break;}
			}//cerr<<'\n';
			//cerr<<i<<' '<<j<<'\n';
			if(can)ans[j]++;
		}
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}

