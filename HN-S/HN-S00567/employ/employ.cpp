#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,ans,c[N],bk[N],p[N];
char a[N];
void dfs(int step){
	if(step>n){
		int fl=0;
		for(int i=1;i<=n;i++)
			if(fl>=c[p[i]]||a[i]=='0')fl++;
		if(n-fl>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bk[i])continue;
		bk[i]=1,p[step]=i,dfs(step+1),bk[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){dfs(1),cout<<ans;return 0;}
	if(m==n){
		for(int i=1;i<=n;i++)if(a[i]=='0'){cout<<0;return 0;}
		for(int i=1;i<=n;i++)if(c[i]==0){cout<<0;return 0;}
		cout<<1;
		return 0;
	}
	return 0;
}
