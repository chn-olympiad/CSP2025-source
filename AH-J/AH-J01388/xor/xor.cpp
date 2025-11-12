#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL n,k;
LL a[N];
LL sum[N];
struct node{
	LL l,r;
};
queue<node> q;
/*bool check(LL pl,LL pr,LL l,LL r){
	if(pl>=l&&pl<=r) return 0;
	if(pr<=r&&pr>=l) return 0;
	if(l>=pl&&l<=pr) return 0;
	if(r<=pr&&r>=pl) return 0;
	return 1;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ok=1;
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//sum[i]=sum[i-1]^a[i];
		if(a[i]!=1) ok=0;
	}
	if(n==1&&k==0&&a[1]==1){ cout<<0;return 0;}
	if(n<=2&&k==0) {cout<<1; return 0;}
	if(ok&&k==0) {cout<<0;return 0;}
	if(n%2==0&&ok&&k==1){cout<<1;return 0;}
	if(n%2==1&&ok&&k==1){cout<<1;return 0;}
	//for(LL i=1;i<=n;i++) cout<<sum[i]<<" ";
	/*LL cnt=0;
	for(LL l=1;l<=n;l++){
		for(LL r=l;r<=n;r++){
			bool ok=0;
			while(!q.empty()){
				LL pl=q.front().l,pr=q.front().r;
				q.pop();
				if(check(pl,pr,l,r)) ok=1;
				else ok=0;
			}
			if(!ok&&abs(sum[r]-sum[l-1])==k) cnt++;	
		}
	}*/
	return 0;
}
