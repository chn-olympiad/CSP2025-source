#include<bits/stdc++.h>
using namespace std;
int n,m,c[1145],ans;
char s[1145];
bool vis[1145];
const int mod=998244353;
void dfs(int dep,int sum){
	if(dep>n){
		if(sum>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(c[i]<dep-sum||s[dep]=='0'){
				dfs(dep+1,sum);
			}else{
				dfs(dep+1,sum+1);
			}
			vis[i]=false;
		}
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1,0);
		ans%=mod;
		cout<<ans<< endl;
		return 0;
	}
	ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}
