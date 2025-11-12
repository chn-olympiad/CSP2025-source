//GZ-S00367 贵阳市第一中学 罗浚瑜 
#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,ans,l;
char s[N];
bool vis[N],gu[N];
int t[N],c[N];
bool pd(){
	int cnt=0,cur=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[t[i]]) continue;
		if(s[i]=='0') cnt++;
		else cur++;
	}
	return cur>=m;
}
void dfs(int x){
	if(x>n){
		ans=(ans+pd())%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;t[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
