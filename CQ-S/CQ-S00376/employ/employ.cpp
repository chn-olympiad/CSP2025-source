#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int N=1005,mod=998244353;
int n,m,k,c[N],ans=0,vis[N],b[N],ret,cnt=0;
string s;
void dfs(int now){
	if(now>n){
		ret=0;
		cnt=0;
		for(int i = 1 ; i <= n ; i++){
			if(s[i]=='0'&&ret>=c[b[i]]){
				ret++;
			}
			else if(s[i]=='1'){
				ret++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			vis[i]=1;
			b[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i = 1 ; i <= n ; i++){
		cin>>c[i];
	}
	for(int i = 1 ; i <= n ; i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 
