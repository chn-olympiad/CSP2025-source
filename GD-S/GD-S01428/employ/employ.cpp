#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll N=5e2+10,mod=998244353;
ll n,m,c[N],t[N],tag[N],ans;
bool vis[N];
void dfs(ll pos){
	if(pos>n){
		ll sum=0,pre=0;
		for(int i=1;i<=n;i++){
			if(!tag[i]||pre>=c[t[i]]) pre++;
			else sum++;
		}
		if(sum>=m) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		t[pos]=i;
		vis[i]=1;
		dfs(pos+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++){
		char s; 
		scanf("%c",&s);
		tag[i]=s-'0';
	}
	for(int i=1;i<=n;i++) read(c[i]);
	dfs(1);
	write(ans);
	return 0;
}
/*
10pts

ci放在

考虑性质A

那么这个时候要考虑0放在哪

把排列转换成另一个东西

->图论？

状压？ 

啊呀是排列

口阿口牙，马亥歹匕手戈力 
*/
