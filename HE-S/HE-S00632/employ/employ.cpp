#include<bits/stdc++.h>
using namespace std;
#define ll long long
void st(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int nm=1e6+10;
int n,m,k,ans,cnt,p=998244353;
int a[nm],vis[nm],b[nm];
char c[nm];
void dfs(int id){
	if(id==n+1){
		int f=0;
		//for(int i=1;i<=n;i++) cout<<b[i]<<' ';
		
		for(int i=1;i<=n;i++){
			if(c[i]=='0'||f>=a[b[i]]) f++;
		}
		if(n-f>=m){
			ans++;
			//cout<<"YES";
		}
		//cout<<"!!!"<<n-f<<'\n';
		ans%=p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[id]=i;
			vis[i]=1;
			dfs(id+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	st();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]) cnt++;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
