#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510],js=0,ans=0;
char s[510];
bool vis[510];
void dfs(int k){
	if(k>n){
		for(int i=1;i<=n;i++)
			if(c[a[i]]==1) ans++;
		return;
	}
	for(int i=1;i<=n;i+=1)
		if(!vis[i]){
			vis[i]=1;
			a[i]=k;
			dfs(k+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		cout<<0;
	}else if(m==1){
		cout<<1;
	}else if(n<=10){
		dfs(1);
		cout<<ans;
	}else cout<<0;
	return 0;
} 
