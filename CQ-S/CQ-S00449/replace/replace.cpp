#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s[200005][3],t1,t2,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int len_t=t1.size();
		for(int i=1;i<=n;i++){
			int len_s=s[i][1].size();
			for(int j=0;j<len_t-len_s+1;j++){
				bool f=1;
				for(int k=0;k<len_s;k++){
					if(t1[j+k]!=s[i][1][k]){
						f=0;
						break;
					}
				}
				if(f){
					y=t1;
					for(int k=0;k<len_s;k++){
						t1[j+k]=s[i][2][k];
					}
					if(t1==t2){
						ans++;
					}
					t1=y;
				}
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
} //25pts
