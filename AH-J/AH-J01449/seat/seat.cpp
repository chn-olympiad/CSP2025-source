#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10+10,M=10+10;
struct node{
	ll cj,id;
}a[N*M];
ll n,m,vis[N][M];
bool cmp(const node &x,const node &y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n*m;i++){
		scanf("%lld",&a[i].cj);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	ll pos,d=1,i=1,j=1,t=0;
	for(ll i=1;i<=n*m;i++)
		if(a[i].id==1) pos=i;
	while(1){
		if(i>n||j>m) break;
		t++;
		vis[i][j]=t;
		if(d==1){
			if(i==n){
				j++;
				d=2;
			}else i++;
		}else if(d==2){
			if(i==1){
				j++;
				d=1;
			}else i--;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(vis[i][j]==pos){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
