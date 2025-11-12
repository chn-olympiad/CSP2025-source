#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
int a[5005], ans=0, n;
//从x 数量 最大 
void dfs(int x, int sum, int ma){
	if(sum>ma*2){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],max(ma,a[i]));
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(0,0,0);
	cout << ans%mod;
	return 0;
}

