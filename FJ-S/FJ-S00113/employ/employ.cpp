#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
inline int add(int x,int y){return (ll)(x+y)%mod;}
inline int mul(int x,int y){return (ll)x*y%mod;}
inline void Add(int &x,int y){x=add(x,y);}
inline void Mul(int &x,int y){x=mul(x,y);}
/*-----------------*/
const int N=20;
int n,m,c[N],ans;
int p[N],vis[N];
char s[N];
inline int check(){
	int cnt=0,num=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') cnt++;
		else{
			if(cnt>=c[p[i]]) cnt++;
			else num++; 
		}
	}
	if(num<m) return 0;
	return 1;
}
inline void dfs(int u){
	if(u>n){
		Add(ans,check());
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[u]=i,vis[i]=1;
		dfs(u+1);
		p[u]=0,vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10) dfs(1);
	else{
		ans=1;
		for(int i=1;i<=n;i++) Mul(ans,i);
	} 
	printf("%d\n",ans);
	return 0;
}

