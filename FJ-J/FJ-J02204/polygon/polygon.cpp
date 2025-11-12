#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5001,mod=998244353;
ll n,a[N],fact[N],ans[N],res=1;
bool t[N]; 
bool check(ll a[],ll len){//检查是否合规 
	ll sum=0;
	for (int i=1;i<=len-1;i++){
		sum+=a[i];
	}
	if (sum>a[len])return 1;
	else return 0;
}
ll qpow(ll a,ll b){//快速幂 
	ll res=1;
	while (b){
		if (b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll C(ll a,ll b){//组合数 
	return fact[b]*qpow(fact[a]*fact[b-a]%mod,mod-2)%mod;
}
void slove(ll step,ll p,ll tt){//神秘暴力，怎么调出来的我也不知道awa 
	if (step==n+1)return;
	if (step-1>=3){
		if (check(ans,step-1)){
			res++;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]==p and i<=tt)continue;
		if (!t[i] and a[i]>=p){
			t[i]=1;
			ans[step]=a[i];
			slove(step+1,a[i],i);
			t[i]=0;
		}
	}
}
int main(){//
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if (n<=3){//神秘特殊样例1 12~
		if (check(a,n)){
			printf("%lld",1);
		}else{
			printf("%lld",0);
		}return 0;
	}
	if (a[n]==1){//神秘特殊样例2 20~
		printf("%lld",C(3,n)%mod);
		return 0;
	} 
	//放弃大点 ——暴力 2^n法 
	slove(1,0,-1);
	printf("%lld",res);
	return 0;//感谢多年OI的陪伴，愿今年圆梦，也祝所有OIer圆梦 
}
/*
1 1 1 ->1
1 1 1 1...n
C(3,n)=n!/3!(n-3)! 
4!=24/6
1 1 1 1 1
5000!/3!*4997!
*/
