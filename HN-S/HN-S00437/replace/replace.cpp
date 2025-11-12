#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,q;
string s[N][2],st,ed;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0]==s[i][1]) continue;
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
	}
	while(q--){
		cin>>st>>ed;
		st=" "+st;ed=" "+ed;
		int len=st.size()-1;
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j+s[i][0].size()-1-1<=len;++j){
				int cnt1=0;
				int cnt2=0;
				for(int k=j;k<=j+s[i][0].size()-1-1;++k) cnt1+=(st[k]==s[i][0][k-j+1]);
				for(int k=j;k<=j+s[i][1].size()-1-1;++k) cnt2+=(ed[k]==s[i][1][k-j+1]);
				for(int k=1;k<j;++k) cnt1+=(st[k]==ed[k]),cnt2+=(st[k]==ed[k]);
				for(int k=j+s[i][0].size()-1;k<=len;++k) cnt1+=(st[k]==ed[k]),cnt2+=(st[k]==ed[k]);
				if(cnt1==cnt2&&cnt1==len) ++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
bc de
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
