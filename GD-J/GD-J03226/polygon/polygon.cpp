#include<bits/stdc++.h>
using namespace std;
int n,a[100];
long long c;
long long g(int G){
	long long ans=1;
	for(int i=0;i<G;i++)ans=(ans*2)%998244353;
	return ans;
}
long long f(int x,int y,int z){
	if(x<y){
		if(z>a[y])return g(y-x);
		if(z==a[y])return g(y-x)-1;
		return (f(x+1,y,z+a[x])+f(x+1,y,z))%998244353;
	}
	if(z>a[y])return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=n-1;i>1;i--)c=(c+f(0,i,0))%998244353;
	printf("%d",c);
	return 0;
}
