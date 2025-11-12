#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e3+10;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int vis[N],a[N];
int ans;

void DFS(int x){
	if(x==n+1){
		int su=0,sum=0;
		for(int i=1;i<=n;i++){
			if(su>=c[a[i]]){
				su++;
				continue;
			}
			if(s[i]=='0') su++;
			else sum++; 
		}
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i;
		vis[i]=1;
		DFS(x+1);
		vis[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	DFS(1);
	cout<<ans<<endl;
	return 0;
}
