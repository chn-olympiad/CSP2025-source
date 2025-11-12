#include<bits/stdc++.h> 
using namespace std;
int a[505],t[505];
const int mod=998244353;
int n,k,cnt;
string s;
int vis[505];
void dfs(int x,int y,int z){
	if(y==k){
		cnt+=x+1;
		cnt%=mod;
		return;
	}
	if(x==0){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(t[i]>=z&&s[n-x]=='1'){
			dfs(x-1,y+1,z);
		}else{
			dfs(x-1,y,z+1);
		} 
		vis[i]=0;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	dfs(n,0,0);
	cout<<cnt;
	return 0;
}
