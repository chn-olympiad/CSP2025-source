#include<iostream>
#include<string.h>
using namespace std;
#define LL long long
const LL N=510,M=998244353;
LL n,m,i,c[N],l[N],r[N],h[N],ans,f[N][N];
bool t[N];
char s[N];
void dfs(LL count,LL ko){
	LL i,k=count+ko+1;
	if(k>n){
		if(count>=m) ans=(ans+1)%M;
		return;
	}
	for(i=1;i<=n;i++){
		if(t[i]) continue;
		t[i]=1;
		if(s[k]=='1'&&c[i]>ko){
			dfs(count+1,ko);
		}
		else dfs(count,ko+1);
		t[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%lld%lld%s",&n,&m,s+1);//01À≥–Ú”–”∞œÏ 
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		h[c[i]]++;
	}
	for(i=1;i<=n;i++){
		l[i]=h[i-1]+l[i-1];
	}
	for(i=n-1;i>=0;i--){
		r[i]=h[i+1]+r[i+1];
	}
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
}
