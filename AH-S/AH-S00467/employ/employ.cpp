#include<bits/stdc++.h>
using namespace std;
const int MOD=988244353;
int n,m,pai[505],ans;
string s;
bool vis[505];
void dfs(int come,int success,int fail){
	if(come==n){
		if(success>=m){
			ans++;
		}
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}else{
			vis[i]=1;
			if(fail>=pai[i]||s[come]=='0'){
				dfs(come+1,success,fail+1);
			}else{
				dfs(come+1,success+1,fail);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
		if(pai[i]==0){
			cnt0++;
		}
	}
	bool flag=0;
	int cnt=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			cnt++;
			flag=1;
		}
	}
	if(!flag){
		int ans=1;
		for(int i=1;i<=len-cnt;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%MOD;
	return 0;
}
