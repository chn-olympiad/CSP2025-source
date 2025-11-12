#include<bits/stdc++.h>
#define ll long long 
#define mod 998244353
using namespace std;
const int N=550;
int c[N],n,m;
string s;
bool vis[N];
int num[N],ans;
bool check(){
	int cnt=0,mis=0;
	for(int i=1;i<=n;++i){
		if(mis>=num[i]||s[i]==0){
			mis++;
		}
		else{
			cnt++;
		}
	}
	return cnt>=m;
}
void dfs(int u){
	if(u>n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==false&&i!=u){
			vis[i]=true;
			num[u]=c[i];
			dfs(u+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s="~"+s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans%mod<<"\n"; 
	return 0;
}
