#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const ll mod = 998244353;
int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){w=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*w;
}
int n,m,c[N];
char s[N]; 
int a[N];
ll ans;
int sum,num,vis[N];
void dfs(int p){
	if(p==n+1){
		if(num>=m)++ans;
		return;
	}
	for(int i = 1;i <= n;++i){
		if(vis[i])continue;
		vis[i]=1;
		if(a[p]==0&&sum<c[i])num++;
		else sum++;
		dfs(p+1);
		vis[i]=0;
		if(a[p]==0&&sum<c[i])num--;
		else sum--;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	int flag=0;
	for(int i = 1;i <= n;++i){
		a[i]=(s[i]-'0')^1;
		flag|=a[i];
	}
	if(!flag){
		ans = 1;
		for(int i = 2;i <= n;++i){
			ans = ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i = 1;i <= n;++i){
		c[i]=read();
	}
	dfs(1);
	printf("%d",ans);
	return 0;
} 
