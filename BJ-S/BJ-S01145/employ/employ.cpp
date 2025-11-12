#include<bits/stdc++.h>
using namespace std;
int a[100005];
int vis[100005];
int box[10005];
int n,m;
long long ans;
string s;
void dfs(int x){
	if(x==n+1){
		int qt=0;
		long long ansx=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				qt++;
				continue;
			}if(qt>=box[i]){
				qt++;
				continue;
			}
			ansx++;
		}
		if(ansx>=m){
			ans++;
			ans=ans%998244353;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			box[x]=a[i];
			vis[i]++;
			dfs(x+1);
			vis[i]--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int u=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=0;i<=n-1;i++)
		if(s[i]=='1') u++;
	if(u==n){
		ans=1;
		for(int i=n;i>=1;i--){
			ans=(ans*i)%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
