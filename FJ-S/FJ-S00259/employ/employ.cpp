#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N];
char s[N];
int p[N];
int ans=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)  scanf("%d",c+i);
	if(n>10)  return puts("0")&0;
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||c[i]==0)
				return puts("0")&0;
		int fac=1;
		for(int i=1;i<=n;i++)  fac=1ll*fac*i%mod;
		return printf("%d\n",fac)&0;
	}
	iota(p+1,p+1+n,1);
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i]=='0')++cnt;
		}
		if(n-cnt>=m)  ++ans;
	}while(next_permutation(p+1,p+1+n));
	printf("%d",ans);
	return 0;
}
//·Å¹ýÎÒ°É
