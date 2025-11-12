#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200010][2],t[2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int j=1;j<=q;j++){
		cin>>t[0]>>t[1];
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t[0]==s[i][0]&&t[1]==s[i][1]){
				ans++;
			}
			else if(s[i][0].find(t[0])!=-1&&s[i][1].find(t[1])!=-1){
				if(s[i][0].find(t[0])==s[i][1].find(t[1])){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
