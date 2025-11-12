#include<iostream> 
#include<algorithm> 
#include<cstdio> 
#include<cmath>

using namespace std;
const int MOD=998244353;
int n,m;
long long ans=1,ans1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int j=1;j<=n-m;j++){
		ans1=1;
		for(int i=n;i>=j;i--){
			ans1*=i;
			ans1%=MOD;
		}
		ans+=ans1;
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
