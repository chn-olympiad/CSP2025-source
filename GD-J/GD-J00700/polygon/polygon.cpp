#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5;
const int V=5e3+5;
const int MOD=998244353;
int n;
int a[N],maxv=-1;
long long now[V][2],sum[V],pow2=4,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxv=max(maxv,a[i]);
	sort(a+1,a+n+1);
	now[0][0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			ans=((ans-sum[a[i]]+pow2)%MOD+MOD)%MOD;
			pow2=2ll*pow2%MOD;
		}
		for(int j=0;j<a[i];j++){
			now[j][i&1]=now[j][(i&1)^1];
			sum[j]=(sum[j-1]+now[j][i&1])%MOD;
		}
		for(int j=a[i];j<=maxv;j++){
			now[j][i&1]=(now[j][(i&1)^1]+now[j-a[i]][(i&1)^1])%MOD;
			sum[j]=(sum[j-1]+now[j][i&1])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
