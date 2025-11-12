#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10005],ans;
const ll p=998244353;
void f(ll x,ll y,ll z,ll s){
	ans%=p;
	if(x>n)return ;
	f(x+1,y,z,s);
	if(y+a[x]>max(z,a[x])*2&&s+1>=3)ans++;
	f(x+1,y+a[x],max(z,a[x]),s+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n<=20){
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		f(1,0,0,0);
		printf("%lld",ans%p);
	}
	else {
		for(int i=3;i<=n;i++){
			ll t=1,t1=1;
			for(int j=n,k=1;k<=i;j--,k++){
				t*=j,t1*=k;
				t%=p,t1%=p;
			}
			ans+=t/t1;
			ans%=p;
		}
		printf("%lld",ans);
	}
	return 0;
}

