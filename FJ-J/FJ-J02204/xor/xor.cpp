#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,a[N],pxor[N],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	pxor[0]=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pxor[i]=a[i]^pxor[i-1];
	}
	ll r=0;//上一区间的右端点 
	for (int i=1;i<=n;i++){
		for (int j=i;j>r;j--){
			if ((pxor[i]^pxor[j-1])==k){
				sum++;
				r=i;
				break;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
/*
1 2 3 4 5
1 10 11 100 101
1 11 00 100 001
5 4 3 3 1
101 100 11 11 1
101 001 10 01 0
xor[l,r]=pxor[r]+pxor[l-1]
*/ 
