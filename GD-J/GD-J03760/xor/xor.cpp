#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,m,l,r,cnt=0,sum;
int a[1234567];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	l=1;
	r=n;
	sum=a[l];
	while(l<=r){
		sum=(sum^a[r]);
		if(sum==k)cnt++;
		if(sum>k)l--,r--;
		else l++;
	}
	printf("%lld",cnt);
	return 0;
}
