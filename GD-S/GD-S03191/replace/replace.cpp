#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N=2e3+5;
const uLL MOD=2080531;

int n,q;
int len[N];
uLL a[N],b[N];
char c[N],d[N];
uLL x[N],y[N];
uLL fac[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",c+1,d+1);
		len[i]=strlen(c+1);
		for(int j=1;j<=len[i];j++){
			a[i]=a[i]*MOD+c[j]-'a';
			b[i]=b[i]*MOD+d[j]-'a';
		}
	}
	
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=MOD*fac[i-1];
	
	while(q--){
		scanf("%s%s",c+1,d+1);
		int l=strlen(c+1);
		for(int i=1;i<=l;i++){
			x[i]=x[i-1]*MOD+c[i]-'a';
			y[i]=y[i-1]*MOD+d[i]-'a';
		}
		LL ans=0;
		for(int i=1;i<=l;i++){
			for(int j=1;j<=n;j++){
				if(l-i+1<len[j]) continue;
				if(x[i+len[j]-1]-x[i-1]*fac[len[j]]!=a[j]) continue;
				uLL nw;
				nw=((x[i-1]*fac[len[j]]+b[j])*fac[l-(i+len[j]-1)])+
					x[l]-x[i+len[j]-1]*fac[l-(i+len[j]-1)];
				if(nw==y[l]) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

