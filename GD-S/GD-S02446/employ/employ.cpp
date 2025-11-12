#include<bits/stdc++.h>
using namespace std;
int n,m,a[20],c[20],d[20],vis[20],ans;
string s;
void dfs(int x){
	if(x>n){
		int cnt=0,sl=0;
		for(int i=1;i<=n;i++){
			if(a[i-1]==0||c[d[i]]<=sl)sl++;
			else cnt++;
		}
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			d[x]=i;
			dfs(x+1);
			vis[i]=0;
			d[x]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
