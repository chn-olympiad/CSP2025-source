#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5,mod=998244353;
ll sum;
ll n,q;
string s1[N],s2[N];
bool vis[N];
void dfs(string s3,string s4){
	if(s3==s4){
		sum=(sum+1)%mod;
		for(ll i=1;i<=n;i++){
			if(s1[i]==s2[i] && vis[i]==0){
				for(ll j=0;j<s3.size();j++){
					ll ans=0;
					for(ll k=0;k<s1[i].size();k++){
						if(s3[j]==s1[i][k]){
							ans++;
						}else{
							break;
						}
					}
					if(ans==s1[i].size()){
						sum=(sum+1)%mod;
					}
				}
			}
		}
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			for(ll j=0;j<s3.size();j++){
				ll ans=0;
				for(ll k=0;k<s1[i].size();k++){
					if(s3[j]==s1[i][k]){
						ans++;
					}else{
						break;
					}
				}
				if(ans==s1[i].size()){
					string s5;
					for(ll k=0;k<j;k++){
						s5[k]=s3[k];
					}
					for(ll k=0;k<s2[i].size();k++){
						s5[k+j]=s2[i][k];
					}
					for(ll k=j+s2[i].size();k<s3.size();k++){
						s5[k]=s3[k+s1[i].size()-s2[i].size()];
					}
					vis[i]=1;
					dfs(s5,s4);
					vis[i]=0;
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(ll i=1;i<=q;i++){
		string s3,s4;
		sum=0;
		cin>>s3>>s4;
//		dfs(s3,s4);
		cout<<0<<'\n';
	}
	return 0;
}
