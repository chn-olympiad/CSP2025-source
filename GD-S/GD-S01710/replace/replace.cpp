#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long 
using namespace std;
const ll N=2000010 ;
const ull Ra=131;
void fil() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout) ;
}
ull ha[N],pf[N],hb[N] ;
ull HASH(ull val,int l,int r,ull x,ull y) {
	ull tmp=val ;
	tmp=tmp-pf[l-1]*x+pf[l-1]*y ;
	return tmp ;
}
ll n,m,s1,t1;
ll len[N] ;
char s[N] ;
char t[N] ;
//void write(ull x) {
//	if(x==0) return ;
//	write(x/10) ;
//	putchar(x%10+'0') ;
//}
ull hha[N],hhb[N] ;
int main() 
{
	fil() ;
	scanf("%lld%lld",&n,&m) ;
	pf[0]=1 ;
	for(int i=1;i<N;i++) pf[i]=pf[i-1]*Ra;
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1) ;
		scanf("%s",t+1) ;
		s1=strlen(s+1) ;
		t1=strlen(t+1) ;
		for(int j=1;j<=s1;j++) {
			ha[i]=ha[i]+s[j]*pf[j-1];
		}
		for(int j=1;j<=t1;j++) {
			hb[i]=hb[i]+t[j]*pf[j-1];
		}
		len[i]=s1;
	}
	
	for(int tt=1;tt<=m;tt++) {
		scanf("%s",s+1) ;
		scanf("%s",t+1) ;
		s1=strlen(s+1) ;
		t1=strlen(t+1) ;
		if(s1!=t1) {
			printf("0\n") ;
			continue ;
		}
		for(int i=1;i<=s1;i++) {
			hha[i]=hha[i-1]+s[i]*pf[i-1];
		}
		for(int i=1;i<=t1;i++) {
			hhb[i]=hhb[i-1]+t[i]*pf[i-1];
		}
		ll ans=0;
		for(int x=1;x<=s1;x++) {
			if(s[x-1]!=t[x-1]) {
				break ;
			}
			for(int i=1;i<=n;i++) {
				if(x+len[i]-1>s1) continue ;
				if(hha[x+len[i]-1]-hha[x-1]!=ha[i]*pf[x-1]) {
					continue ;
				}
				ull tmp=HASH(hha[s1],x,x+len[i]-1,ha[i],hb[i]) ;
				if(tmp==hhb[t1]) {
					ans++ ;
				}
			}
		}
		printf("%lld\n",ans) ;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
