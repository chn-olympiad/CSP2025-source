#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s[200005][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			int pos=t1.find(s[j][0]);
			string tt=t1;
			while(pos<tt.size()&&pos>=0){
				string t=tt;
				for(int i=0;i<s[j][1].size();i++)
					t[pos+i]=s[j][1][i];
				if(t==t2)ans++;
				tt=tt.substr(pos+s[j][0].size(),tt.size()-pos-s[j][0].size()+1);
				pos=tt.find(s[j][0]);
			}
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}
