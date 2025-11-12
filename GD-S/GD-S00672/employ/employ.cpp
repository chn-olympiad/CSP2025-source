#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,x=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
int n,m,c[666],px[666],vis[666],ans;
string s;
const int mod=998244353;
inline void work(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(sum>=c[px[i]]||(s[i-1]=='0')){
			sum++;
			continue;
		}
	}
	ans+=(sum+m<=n);
	if(ans>=mod)ans-=mod;
}
void dfs(int x){
	if(x==n+1){
		work();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			px[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//wjh
