//CSP-S AK me
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[200005][2];
int n,q,cnt=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		string t1,t2;
		cnt=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string tmp=t1,tmp2;
			for(int k=0;k<=(int)tmp.size()-(int)s[i][0].size();k++){
				tmp=t1;
				tmp2=tmp.substr(k,s[i][0].size());
				if(tmp2==s[i][0]){
					for(int j=k;j<k+(int)s[i][0].size();j++){
						tmp[j]=s[i][1][j-k];
					}
					if(tmp==t2) cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
