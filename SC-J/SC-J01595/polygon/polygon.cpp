#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPJ_2025

#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define fep(i,s,e) for(long long i=s;i<e;i++)
#define per(i,s,e) for(long long i=s;i>=e;i--)
#define pef(i,s,e) for(long long i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
const long long mod=998244353;
long long n,a[5001],ans,inv[5001],now=1,mxx;
long long dp[5005];//sum=i  sum>5000,sum归为5001 
bool flag;
void dfs(long long nw,long long mx,long long sum){
	if(nw==n+1){
		return ;
	}
	dfs(nw+1,mx,sum);
	if(max(mx,a[nw])*2<sum+a[nw]){
		ans++;
		ans%=mod;
	}
	dfs(nw+1,max(mx,a[nw]),sum+a[nw]);
}
void ptm(){
	inv[1]=1;
	rep(i,2,5000){
		inv[i]=(mod-mod/i)*inv[mod%i];
		inv[i]%=mod;
	}
//	cout<<inv[2]<<endl;
}
void sp(){
	ptm();
	rep(i,1,3){
		now*=(n-i+1);
		now%=mod;
		now*=inv[i];
		now%=mod;
	}
//	cout<<now<<endl;
	ans=now;
	rep(i,4,n){
		now*=(n-i+1);
		now%=mod;
		now*=inv[i];
		now%=mod;
		ans+=now;
		ans%=mod;
	}
	print(ans);
}
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPJ_2025
//	freopen("polygon4.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	rep(i,1,n){
		read(a[i]);
		if(a[i]!=1){
			flag=1;
		}
	}
	if(n<=20){
		dfs(1,0,0);
		print(ans);
		return 0;
	}
	if(flag==0){
		sp();
		return 0;
	}
	sort(a+1,a+n+1,less<long long>());
	dp[0]=1;
	rep(i,1,n){
		rep(j,a[i]+1,mxx){
			ans+=dp[j];
			ans%=mod;
		}
		per(j,mxx,0){
			dp[min(5001ll,j+a[i])]+=dp[j];
			dp[min(5001ll,j+a[i])]%=mod;
		}
		mxx+=a[i];
		mxx=min(mxx,5001ll);
	}
	print(ans);
	return 0;
}