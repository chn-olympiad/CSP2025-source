#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5007;
const ll Misaka=998244353;
ll n,a[N],p[N],f[N],d;

int main(){
	freopen("polygon.in" ,"r",stdin );
	freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	p[0]=1; sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=(p[i-1]*2)%Misaka;
	
	for(int i=0;i<=5000;i++) f[i]=1;
	
	for(int i=1;i<=n;i++){
		if(i>=3) d+=(p[i-1]+Misaka-f[a[i]]),d%=Misaka;
		for(int j=5000;j>=0;j--){
			if(j+a[i]<=5000) f[j+a[i]]+=f[j],f[j+a[i]]%=Misaka;
		}
	}
	printf("%lld",d);
	
	return 0;
}

