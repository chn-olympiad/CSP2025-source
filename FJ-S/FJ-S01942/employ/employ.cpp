#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
#define pb push_back
//#define int ll
using namespace std;
inline void dd(int &xx){
	xx=0;
	int ff=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	xx*=ff;
}
const int N=1005,mod=998244353;
int n,m,a[N],b[N],c[N],vis[N],ans;
char s[N];
int check(){
	int sum=0;
	for(int i=1;i<=n;++i){
		if(sum>=c[b[i]]||a[i]==0) ++sum;
	}
	return n-sum;
}
void dfs(int x){
	if(x==n+1){
		if(check()>=m) ++ans;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			b[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			b[x]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	dd(n),dd(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
		b[i]=i;
	}
	for(int i=1;i<=n;++i) dd(c[i]);
	ans=0;
	dfs(1);
	printf("%d\n",ans);
}
