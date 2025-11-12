#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){int x = 0,ch = getchar();bool zt=0;while(ch<48||ch>57){if(ch==45)zt = 1;ch = getchar();}while(ch>=48&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return zt?-x:x;}
const int N = 500 + 10,mod = 998244353;
int n,m,ans,b[N];bool a[N],vv[N];
void dfs(int x,int sum){
	if(n-x+1+(x-sum-1)<m)return;
	if(x==n+1&&n-sum>=m){ans++;ans = ans==mod?0:ans;return;}
	for(int i=1;i<=n;i++)if(!vv[i])
		vv[i] = 1,dfs(x+1,sum+(a[x]==0||sum>=b[i])),vv[i] = 0;
}signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();m = read();bool zt = 1;
	for(int i=1,ch;i<=n;i++){
		do ch = getchar();while(ch<48||ch>57);
		a[i] = ch^48;zt &= a[i];
	}for(int i=1;i<=n;i++)b[i] = read();
	if(zt){
		ans = 1;for(int i=1;i<=n;i++)ans = ans*i%mod;
		cout<<ans;return 0;
	}dfs(1,0);cout<<ans;
	return 0;
}
