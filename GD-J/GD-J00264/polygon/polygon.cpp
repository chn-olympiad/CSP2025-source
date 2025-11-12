#include<iostream>
#include<algorithm>
using namespace std;
const int si=5e3+10,mod=998244353;
#define int long long
int n,ans=0,maxn=0;
int c[si],t[si],cp[si];
//ci->p位置和大于等于i的方案数
//ti->长度为i的木棍个数
//cp->中转至c 
inline C(int i1,int i2){//组合数
	//i1中选i2个 
	int re=1;
	i1=i1-i2+1;
	for(int i=0;i<i2;i++)
		re=(re*(i1+i)/(i+1))%mod;
	return re;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1,in;i<=n;i++)
		scanf("%lld",&in),++t[in],maxn=max(maxn,in);
	for(int i=1;i<=maxn;i++){
		if(t[i]==0)continue;
		cout<<i<<' '<<t[i]<<'\n';
		int sum=0;
		for(int j=3;j<=t[i];j++)
			sum=(sum+C(t[i],j))%mod;
		//选自己多根 
		ans=ans*(sum+C(t[i],2)+1)%mod;
		//自我交配
		ans=(ans+sum)%mod;
		//选自己1根
		ans=(ans+t[i]*c[i+1]%mod)%mod;
		
		//处理当前c 
		//1处理原本c，保留
		//2处理多根 
		for(int j=1;j<=maxn+1;j++)
			for(int k=1;k<=t[i];k++)
				cp[j]=(cp[j]+c[max(j-k*i,1ll)]*C(t[i],k))%mod;
		//4处理自己
		for(int k=1;k<=t[i];k++){
			int cs=C(t[i],k);
			for(int j=1;j<=min(k*i,maxn+1);j++)
				cp[j]=(cp[j]+cs)%mod;
		}
		for(int j=1;j<=maxn+1;j++)
			c[j]=(c[j]+cp[j])%mod,cp[j]=0;
		for(int j=1;j<=maxn+1;j++)
			cout<<c[j]<<' ';
		cout<<'\n';
	}printf("%lld",ans);
	return 0;
}
