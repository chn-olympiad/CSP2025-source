#include<bits/stdc++.h>
using namespace std;
#define N 510
#define mod 998244353

long long read(){
	long long res=0;char c=getchar();bool flag=0;
	while(c<'0'||c>'9'){
		flag|=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	return res * ( flag ? -1 : 1 );
}

int n,m;
string op;
long long dp[(1<<20)][20];
int c[N];

int lowbit(int num){
	int res=0;
	while(num){
		num-=(num&-num);
		res++;
	}
	return res;
}

void Cecilia(){
	n=read();m=read();
	cin>>op;
	for(int i=0;i<n;i++) c[i]=read();
	dp[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int cnt=lowbit(s);
		for(int i=0;i<n;i++){
			if((s>>i)&1) continue;
			for(int k=0;k<=n;k++){
				bool pass=(cnt-k<c[i])&&(op[cnt]=='1');
				if(k+pass<=n) dp[s|(1<<i)][k+pass]=(dp[s|(1<<i)][k+pass]+dp[s][k])%mod;
			}
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
	printf("%lld",ans);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Cecilia();
	return 0;
}
/*
T1 AC at 1:30
T4 20pts at 2:00
T3 >25pts?? at 2:34
at 2:34 : why T2 so difficult,i`m out.i even can`t write a force code
at 2:39 i`m stupid,i know how to do T2
at 2:53 no,i don`t know
T2 48pts at 3:12 
at 3:12 100+20+25+48=203=die
at 3:24 T2 maybe prim but i forget it
at 3:30 i give up,let me check my code.
at 3:49 it`s over.goodbey OI(maybe)
from GrYWnds
*/
