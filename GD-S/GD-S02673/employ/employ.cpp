#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pat[510];
bool vis[510];
string s;
ll ans=0;
ll n,m;
void dfs(ll x,ll refuse,int k,bool vis[]){
	if(k==n){
		if(x>=m){
			ans++;
			ans%=998244353;
		} 
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(refuse>=pat[i]||s[k]-'0'==0){
				dfs(x,refuse+1,k+1,vis);
			}else{
				dfs(x+1,refuse,k+1,vis);
			}
			vis[i]=0;
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>pat[i];
	}
	bool fa=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'!=1){
			fa=0;
			break;
		}
	}
	if(fa){
		for(int i=0;i<s.size();i++){
			//if(s[i]-'0'==0) n--;
		}
		
	}else{
		dfs(0,0,0,vis);
		cout<<ans;
	}
	return 0;
}
