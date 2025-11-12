#include <bits/stdc++.h>
const int maxn=5005;
#define int  long long
using namespace std;
int n;
int a[maxn];
int vis[maxn];
int ans;
bool check(int x,int mx){
	return x>mx*2;
}
void dfs(int s,int x,int he,int mx,int last){
	if(s-x>n-last) return;
	if(x==s+1){
		if(check(he,mx)){
			ans++;
			ans%=998244353;
			he=0;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(s,x+1,he+a[i],max(mx,a[i]),i);
			vis[i]=0;
		}
	} 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,1,0,-999,0);
	}
	cout<<ans%998244353;
}
