#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],u[5005],s,m;
void x(long long l,long long c,long long mx,long long z){
	if(l>=3){
		if(mx*2<2*z)s=(s+c)%998244353;
	}
	for(int i=mx+1; i<=m; i++){
		if(u[i]!=0){
			x(l+1,c*u[i],i,z+i);
		}
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		if(u[a[i]]==0)m=max(m,a[i]);
		u[a[i]]++;
	}
	for(int i=1; i<=m-2; i++){
		if(u[i]!=0){
			x(1,u[i],i,i);
		}
	}
	printf("%lld",s%998244353);
	return 0;
}
