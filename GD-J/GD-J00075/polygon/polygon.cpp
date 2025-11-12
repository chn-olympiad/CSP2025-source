#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e3+10,maxm=maxn*maxn,mod=998244353;
int n,a[maxn];
bool b[maxn];
int ans;
void dfs(int u){
	if(u>n){
		int cnt=0,z=0,m=0;
		for(int i=1;i<=n;i++){
			if(b[i]){
				cnt++;
				z+=a[i];
				m=max(a[i],m);
			}
		}
		if(cnt>=3&&z>2*m)ans++;
		return;
	} 
	b[u]=0;
	dfs(u+1);
	b[u]=1;
	dfs(u+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1);
		cout<<ans;
	}
	return 0;
}
