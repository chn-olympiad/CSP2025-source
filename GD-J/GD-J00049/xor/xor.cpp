#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n, k, a[500010], xo[500010], kk, nn, ans;
struct node{
	ll st, en;
}cnt[50000010];
bool cmp(node x, node y){
	return x.en<y.en;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	xo[1]=a[1];
	for(int i=2; i<=n; i++){
		xo[i]=xo[i-1]^a[i];
	}
	if(n<=1000){
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				int anxo=xo[j]^xo[i-1];
				if(anxo==k){
					cnt[++kk].st=i;
					cnt[kk].en=j;
				}
			}
		}
		sort(cnt+1, cnt+kk+1, cmp);
		for(int i=1; i<=kk; i++){
			if(cnt[i].st>nn){
				ans++;
				nn=cnt[i].en;
			}
		}
		cout<<ans;
	} 
	else{
		int be=1;
		for(int i=1; i<=n; i++){
			for(int j=be; j<=i; j++){
				int anxo=xo[i]^xo[j-1];
				if(anxo==k){
					be=i+1;
					ans++;
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
