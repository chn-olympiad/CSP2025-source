#include<bits/stdc++.h>
namespace umrofcen{
	const int p=998244353;
	char s[555];int n,m,i,j,k,S,T,c[555],f[20][270270];
	int A(int x,int y){return x+=x+y<p?y:y-p;}
	void M(){
		for(scanf("%d%d%s",&n,&m,s);i^n;scanf("%d",c+i++));
		for(i=0,**f=1;!(++i>>n);)for(j=T=__builtin_popcount(i);~j;--j)for(S=i;S;S&=S-1)if(k=__builtin_ctz(S),s[T-1]&1){if(j>c[k])f[j][i]=A(f[j][i],f[j-1][i^(1<<k)]);
		else if(j<c[k])f[j][i]=A(f[j][i],f[j][i^(1<<k)]);}
		else j?f[j][i]=A(f[j][i],f[j-1][i^(1<<k)]):0;
		for(S=0,--i,j=n-m;~j;--j)S=A(S,f[j][i]);printf("%d",S);
	}
};
int main(){return freopen("employ.in","r",stdin),freopen("employ.out","w",stdout),umrofcen::M(),0;}
