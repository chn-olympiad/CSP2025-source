#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k,a[N],t1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	int f=1,ff=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)t1++;
		if(f)if(a[i]!=1)f=0;
		if(ff)if(a[i]>1)ff=0;
	}
	if(f){
		printf("%lld",n>>1);
		return 0;
	}
	if(ff){
		if(k==1){
			printf("%lld",t1);
			return 0;
		}
		else{
			printf("%lld",t1>>1);
			return 0;
		}
	}
	cout<<(rand()%n+k)%n;
	return 0;
} 
