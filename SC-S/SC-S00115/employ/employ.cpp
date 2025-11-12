#include<iostream>
#include<cstdio>
using namespace std;
const int N=100;
int a[N],vis[N],c[N],s[N],n,m,ans;
void dfs(int i){
	if(i==n+1) {
		int cnt=0,t=0;
		for(int j=1;j<=n;j++) {
			if(t>=c[a[j]]){
				t++;
				continue;
			}
			if(s[j]==0){
				t++;
				continue;
			}
			cnt++;
		}
		if(cnt>=m) ans++;
		return;
	}
	for(int j=1;j<=n;j++){
		if(!vis[j]){
			vis[j]=1;
			a[i]=j;
			dfs(i+1);
			vis[j]=0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		char f;
		cin>>f;
		s[i]=f-'0';
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}