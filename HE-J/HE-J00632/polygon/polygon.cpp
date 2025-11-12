#include <bits/stdc++.h>
using namespace std;
long long n,a[5555],vis[5555],cnt;
void dfs(int c,int b){
	if(c){
		long long sum=0,x=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				x=max(x,a[i]);
			}
		}
		if(sum>x*2) cnt++;
		cnt%=998244353;
		if(c==n || b>n) return;
	}
	for(int i=b;i<=n;i++){
		vis[i]=1;
		dfs(c+1,i+1);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,1);
	cout<<cnt%998244353;
	return 0;
}

