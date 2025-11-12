#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[200002],t[200002];
void solve(){
	int L1=0;
	int n,q;cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s[i]>>t[i],L1+=(int)s[i].size();
		while (q--){
			int ans=0;
			string s1,s2;cin>>s1>>s2;
			int le=s1.size(),lee=s2.size();
			if (le!=lee){
				cout<<0<<endl;
				continue;
			}
			string f;
			int fails=0,l=1;
			for (int i=0;i<le;i++){
				if (s1[i]!=s2[i]){
					fails=i;
					while (i<le-1&&s1[i+1]!=s2[i+1]) i++,l++;
					break;
				}
			}
			int failt=fails+l-1;
			string ss1=s1.substr(fails,l),ss2=s2.substr(fails,l);
//			cout<<ss1<<endl<<ss2<<endl;
			for (int i=1;i<=n;i++){
				int ll=s[i].size();
				if (ll>le) continue;
				if (ll==l){
					if (s[i]==ss1&&t[i]==ss2) ans++;
				}
				else if (ll>l){
//					cout<<ll<<endl;
					bool jug=0;
					for (int j=0;j<=ll-l;j++){
//						cout<<s[i][j]<<endl;
						if (s[i][j]==ss1[0]){
//							cout<<s[i].substr(j,ll-j)<<endl;
							if (s[i].substr(j,ll-j)==ss1&&t[i].substr(j,ll-j)==ss2){
								jug=1;
//								cout<<j<<endl;
								for (int k=j-1;k>=0;k--){
									if (fails-j+k<0||s1[fails-j+k]!=s[i][k]||s2[fails-j+k]!=t[i][k]){
										jug=0;
//										cout<<"qwq"<<endl;
										break;
									}
								}
								for (int k=j+l;k<ll;k++){
									if (failt+1+k-j-l>=n||s1[failt+1+k-j-l]!=s[i][k]||s2[failt+1+k-j-l]!=t[i][k]){
										jug=0;
//										cout<<"qwq"<<endl;
										break;
									}
								}
							}
						}
						if (!jug) break;
					}
					if(jug) ans++;
				}
			}
			cout<<ans<<endl;
//			cout<<"qwq"<<endl;
		}
} 
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;
	while (t--) solve();
	return 0;
}

