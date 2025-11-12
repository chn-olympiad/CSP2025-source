#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+4;
const int T=2;
ll n,q,ans;
string s[N][T];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t[T];
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		ll st=-1,ed=-1;
		for(int i=0;i<t[0].size();i++){
			if(t[0][i]!=t[1][i]){
				if(st==-1){
					st=i;
				}
				for(int j=i;j<t[0].size();j++){
					if(t[0][j]==t[1][j]){
						ed=j-1;
						i=j;
						break;
					}
					if(j==t[0].size()-1){
						ed=j;
						i=j;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][0].size()>t[0].size()){
				continue;
			}
			for(int j=0;j<=t[0].size()-s[i][0].size();j++){
				if(j>st||j+s[i][0].size()-1<ed){
					continue;
				}
				bool flag=true;
				for(int k=0;k<s[i][0].size();k++){
					if(t[0][j+k]!=s[i][0][k]||t[1][j+k]!=s[i][1][k]){
						flag=false;
						break;
					}
				}
				if(flag){
					ans++;
					j+=s[i][0].size();
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
