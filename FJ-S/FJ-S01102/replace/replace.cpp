#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200010],t[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		string ss,tt;
		int ans=0;
		cin>>ss>>tt;
		for(int i=0;i<n;i++){
			for(int j=0;j<ss.size();j++){
				int flag=1;
				for(int k=0;k<s[i].size();k++){
					if(j+k>=ss.size()||ss[j+k]!=s[i][k]||tt[j+k]!=t[i][k]){
						flag=0;
						break;
					}
				}
				for(int k=0;k<j;k++){
					if(ss[k]!=tt[k]){
						flag=0;
						break;
					}
				}
				for(int k=j+s[i].size();k<ss.size();k++){
					if(ss[k]!=tt[k]){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
