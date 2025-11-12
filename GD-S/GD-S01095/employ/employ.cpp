#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,s[N],c[N],p[N];
char ch;
long long ans;
bool vis[N];
void dfs(int pos,int lst) {
	if(n-lst<m) return;
	if(pos==n+1) {
		ans++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]==0) {
			vis[i]=1,p[pos]=i;
			if(!s[pos]||c[i]<=lst) dfs(pos+1,lst+1);
			else dfs(pos+1,lst);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>ch;
		if(ch=='1') s[i]=1; 
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
}
//终究还是失败了吗……
//看来我果然一无是处
//哭泣了无数个日夜
//不愿相信面前的事实
//困在自己编的谎言里
//被幻梦包裹住
//什么也不愿学不愿背
//用不可能考掩饰无能
//那就结束在这里吧
//或许这已是我的极限 
