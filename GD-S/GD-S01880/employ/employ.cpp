#include<bits/stdc++.h>
#define rg register
#define il inline
using namespace std;
using i64=long long;
il i64 read(){
	i64 x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);x=x*10+(ch^48),ch=getchar());
	return x;
}
const int maxi=509,mod=998244353;
i64 M,N,s[maxi],s_s[maxi],c[maxi],ans=1;
il void read_s(){
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(int i=1;i<=N;i++){
		s[i]=(ch^48);
		ch=getchar();
	}
	return;
}
#define step il void
namespace sp{
	step m1(){
		
		return;
	}
	step equ(){
		if(s_s[N]==0){
			for(int i=1;i<=N;i++)ans=(ans*i)%mod;
			printf("%lld\n",ans);
		}else{
			puts("0"); 
		}
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	N=read(),M=read();read_s();
	for(int i=1;i<=N;i++){
		s_s[i]=s_s[i-1]+s[i];
	}
	if(s_s[N]>(N-M)){
		puts("0");
		return 0;
	}
	for(int i=1;i<=N;i++)c[i]=read();
	sort(c+1,c+1+N);
	if(N==M)sp::equ();
	else if(M==1)sp::m1();
	else puts("i give up!!!");
	return 0;
}
