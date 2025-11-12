#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
constexpr int MOD=998244353;
int a[6000];//,f[6000][6000];
long long fac[6000];
bool chk(unsigned st){
	int sum=0,ma=0,i=1;
	while(st){
		if(st&1){
			sum+=a[i]%MOD;
			ma=max(ma,a[i]);
		}
		st>>=1;i++;
	}
	return sum>2*ma;
}
int C(int a,int b){
	return (fac[a]%MOD)/fac[b]/fac[a-b];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	bool flag=1;
	long long res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(n<=20){//40pts,2^n*n
		for(unsigned st=0;st<(1u<<n);st++){
			if(chk(st))res=(res+1)%MOD;
		}
		cout<<res;
	}
	else if(flag){//ai==1,24pts
		fac[0]=1;fac[1]=1;
		for(int i=2;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
		long long res=0;
//		for(int i=3;i<=n;i++)cout<<"C "<<n<<","<<i<<"="<<C(n,i)<<endl;
		for(int i=3;i<=n;i++)res=(res+C(n,i))%MOD;
		cout<<res;
	}
	return 0;
}
