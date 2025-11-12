#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,m,k,q,p,tmp,ans,vis[N];
struct node{
	ll cos,l,r;
}a[2*N];
bool cmp(node x,node y){
	return x.cos<y.cos;
}
void sol1(){
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(!vis[a[i].l] || !vis[a[i].r]){
			vis[a[i].l]=1;
			vis[a[i].r]=1;
			ans+=a[i].cos;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&q,&p,&tmp);
		a[i].cos=tmp;
		a[i].l=q;
		a[i].r=p;
	}
	if(k==0){
		sol1();
		printf("%lld",ans);
		return 0;
	}
	printf("0");
} 
