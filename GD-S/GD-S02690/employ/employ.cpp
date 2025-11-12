#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define ppc(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
const int N=20,M=(1<<19),mod=998244353;
int n,m,c[N],f[2][M][N],now,pre=1;
string S;
int add(int x){
	if(x<0)x+=mod;
	if(x>=mod)x-=mod;
	return x;
}
void Write(int x){
	for(int i=1;i<=n;i++)cout<<((x>>(i-1))&1);
	return ;
}
int ans,vis[N];
void dfs(int u,int w){
	if(u==n){
		if(w>=m)ans=add(ans+1);
		return ;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		int flag=1;
		if(S[u]=='0')flag=0;
		if(w>=c[i])flag=1;
		dfs(u+1,w+flag);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>S;
	for(int i=1;i<=n;i++)cin>>c[i];
//	dfs(0,0);
//	cout<<ans;
//	return 0;
	for(int i=1;i<=n;i++)if(c[i])f[now][1<<(i-1)][S[0]-'0']=1;
	else f[now][1<<(i-1)][0]=1;
	for(int i=2;i<=n;i++){
		swap(now,pre);
		for(int j=0;j<(1<<n);j++)if(ppc(j)==i){
			for(int k=1;k<=n;k++)if(j&(1<<(k-1))){
				for(int w=0;w<=i;w++){
					int flag=1;
					if(S[i-1]=='0'||i-1-w>=c[k])flag=0;
//					if(i<=3&&f[pre][j^(1<<(k-1))][w])Write(j^(1<<(k-1))),cout<<" "<<w<<"-->",Write(j),cout<<" "<<w+flag<<"\n";
					f[now][j][w+flag]=add(f[now][j][w+flag]+f[pre][j^(1<<(k-1))][w]);
				}
			}
		}
//		cout<<i<<":\n";
//		for(int j=0;j<(1<<n);j++){
//			for(int w=0;w<=i;w++)if(f[now][j][w]){
//				Write(j);cout<<" "<<w<<": "<<f[now][j][w]<<"\n";
//			}
//		}
		memset(f[pre],0,sizeof f[pre]);
	}
	for(int i=m;i<=n;i++)ans=add(ans+f[now][(1<<n)-1][i]);
	cout<<ans;
	return 0;
}
