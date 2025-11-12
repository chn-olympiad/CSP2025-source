#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],t;
long long xo(long long a,long long b){
	if(a==b) return 0;
	else return 1;
}
void bfs(long long x,long long j){
	for(long long i=j+1;i<n;i++){
		if(xo(x,a[i])==k) t++;
		bfs(xo(x,a[i]),i);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=0;i<n;i++) scanf("%lld",&a[i]);
	for(long long i=0;i<n;i++){
		if(a[i]==k) t++;
		bfs(a[i],i);
	}
	printf("%lld",t);
	return 0;
} 
