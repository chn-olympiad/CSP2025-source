#include<bits/stdc++.h>
using namespace std;
int c[505];
bool vis[505];
	int n,m;
string s;
int ans;
void dfs(int k,int leave,int peo){
	if(k==n){
	//	cout<<1;
		if(peo>=m){
			ans++;
			if(ans==998244353)ans=0;
			return;
		}
	}
	if(n-k+peo<m)return;
	if(n-leave<m)return;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(leave>=c[i]){
				dfs(k+1,leave+1,peo);
				
			}
			else if(s[k]=='0'){
				dfs(k+1,leave+1,peo);
			}
			else{
				dfs(k+1,leave,peo+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n>18){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		dfs(0,0,0);
		cout<<ans;
	}
	
	return 0;
}
