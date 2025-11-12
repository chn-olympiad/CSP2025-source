#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[510],vis[510],ans;
string s;
void dfs(int step,int sum){
	if(n-sum<m)return ;
	if(step>n){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum<c[i]){
				if(s[step-1]=='0')dfs(step+1,sum+1);
				else dfs(step+1,sum);
			}
			else{
				dfs(step+1,sum+1);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
//	cout<<s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
}
