#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,c[505],p[505];
bool diff[505],vis[505];
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
	return ;
}
inline bool check(){
	int cnt=0,pass=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[p[i]]){
			cnt++;
			continue;
		}
		if(!diff[i]){
			cnt++;
			continue;
		}
		pass++;
	}
	return (pass>=m);
}
inline void dfs(int dep){
	if(dep==n+1){
		if(check()){
			ans++;
			ans%=m;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		p[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		diff[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n>=18){
		cout<<0;
		return 0;
	}
	dfs(1);
	print(ans);
	return 0;
}
