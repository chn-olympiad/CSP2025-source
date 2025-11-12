#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
struct node{int a,b,c;}a[maxn],dp[maxn];
bool cmp(node x,node y){
	if(x.a!=y.a)return x.a>y.a;
	if(x.b!=y.b)return x.b>y.b;
	return x.c>y.c;
}
int n,ans;
void dfs(int now,int x,int y,int z,int sum){
	if(now==n+1){
		if(x<=n/2&&y<=n/2&&z<=n/2){
			ans=max(ans,sum);
			return;
		}
	}
	if(x<n/2)dfs(now+1,x+1,y,z,sum+a[now].a);
	if(y<n/2)dfs(now+1,x,y+1,z,sum+a[now].b);
	if(z<n/2)dfs(now+1,x,y,z+1,sum+a[now].c);
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++)a[i].a=read(),a[i].b=read(),a[i].c=read();
	if(n<=13){
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		return;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int b=max({dp[i-1].a,dp[i-1].b,dp[i-1].c});
		dp[i].a=b+a[i].a;
		dp[i].b=b+a[i].b;
		dp[i].c=b+a[i].c;
	}
	cout<<max({dp[n].a,dp[n].b,dp[n].c})<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		solve();
	}
	return 0;
}
