#include<iostream>
using namespace std;
int n,m,b[501],cnt;
long long ans;
char c;
bool a[501],vis[501];
void dfs(int x,int y){
	if(x==n){
		if(x-y>=m) ans++;
		ans%=988244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]&&y<b[i]) dfs(x+1,y);
			else dfs(x+1,y+1);
			vis[i]=0;
		}
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	if(cnt==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=n;
			ans%=988244353;
		}
		cout<<ans;
	}else{
		if(m>cnt) cout<<0;
		else{
			dfs(0,0);
			cout<<ans;
		}
	}
}
