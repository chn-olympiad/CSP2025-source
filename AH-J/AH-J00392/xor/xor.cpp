#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans, maxl, id, c[500005];
struct node{
	long long p, f, d;
}b[1000005];
bool cmp(node x, node y){
	if(x.p==y.p) return x.d<y.d;
	return x.p<y.p;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]==k){
			b[++id].p=i, b[id].f=0, b[id].d=id;
			b[++id].p=i, b[id].f=1, b[id].d=id-1;
		}
		a[i]=a[i-1]^a[i];
		if(a[i]==k){
			b[++id].p=1, b[id].f=0, b[id].d=id;
			b[++id].p=i, b[id].f=1, b[id].d=id-1;
		}
	}
	for(long long i=2; i<n; i++){
		for(long long j=i+1; j<=n; j++){
			if((a[j]^a[i-1])==k){
			b[++id].p=i, b[id].f=0, b[id].d=id;
			b[++id].p=j, b[id].f=1, b[id].d=id-1;
			}
		}
	}
	sort(b+1, b+1+id, cmp);
	for(long long i=1; i<=id; i++){
		if(b[i].f==0){
			c[b[i].d]=maxl+1;
		}
		else{
			maxl=c[b[i].d];
		}
	}
	for(long long i=1; i<=id; i++){
		ans=max(ans, c[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
