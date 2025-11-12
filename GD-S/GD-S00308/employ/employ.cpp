#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int fg=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fg=-fg;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return fg*x;
}
int n,m,c[501],f[501],ans;
bool vis[501];
string s;
bool check(){
	int sum=0,l=0;
	for(int i=1;i<=n;i++){
		if(c[f[i]]<=l){
			if(m==n) return false;
			l++;
			continue;
		}
		if(s[i-1]=='0'){
			l++;
		}
		else {
			sum++;
			if(sum>=m) return true;
		}
	}
	return false;
}
void dfs(int x){
	if(x>n){
		if(check()) ans=(ans+1)%998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			f[x]=i;
			dfs(x+1);
			vis[i]=false;
		}
	} 
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	std::cin>>s;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
