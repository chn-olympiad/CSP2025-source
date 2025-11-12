#include<iostream>
using namespace std;
int n,m,a[505],b[505],vis[505],ans,mod=998244353;
string s;
void dfs(int x){
	if(x==n+1){
		int d=0,g=0;
		for(int i=1;i<x;i++){
			if(d>=a[b[i]]){
				d++;
				continue;
			}
			if(s[i-1]=='0')d++;
			else g++;
		}
		cout<<d<<" "<<g<<endl;
		if(g>=m)ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
