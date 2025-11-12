#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],b[500005];
long long mn(long long l,long long r){
	if(l==r){
		return a[l];
	}
	else return b[l-1]^b[r];
}
long long bfs(long long l,long long r){
	if(l==r) {return a[l]==k;}
	int ans=int(mn(l,r)==k);
	for(int i=l;i<r;i++){
		int j=bfs(l,i)+bfs(i+1,r);
		if(j>ans) {ans=j;}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	scanf("%lld",&a[1]);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	long long ans=bfs(1,n);
	printf("%lld",ans);
	return 0;
}
