#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],vis[505],cnt,ans,b[505];
char ch[505];
void dfs(int x,int c,int t){
	if(x==n+1){
		if(c>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=i;
			if(ch[x]=='0'||t>=a[i]){
				dfs(x+1,c,t+1);
			}
			else{
				dfs(x+1,c+1,t);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
		cnt+=ch[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt--;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(cnt==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}