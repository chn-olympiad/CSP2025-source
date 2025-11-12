#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
char s[N];
int c[N],n,m,ans,vis[N],b[N];
void dfs(int x,int cnt){
	if(x>n){
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<endl<<cnt<<endl;
		if(n-cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vis[i]=true;
			b[x]=i;
			if(s[x]=='0'||c[i]<=cnt){
				dfs(x+1,cnt+1);
			}
			else{
				dfs(x+1,cnt);
			}
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
