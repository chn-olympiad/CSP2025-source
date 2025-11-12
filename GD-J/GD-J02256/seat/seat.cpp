#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[100005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,cmp);	
	ll t=0;
	for(int i=1;i<=n;i++){
		if(i%2==0)
			for(int j=m;j>0;j--){
				t++;
				if(a[t]==k){
					printf("%d %d",i,j);
					return 0;
				}
			}
		else 
			for(int j=1;j<=m;j++){
				t++;
				if(a[t]==k){
					printf("%d %d",i,j);
					return 0;
				}
			}		
	}
	
	return 0;
}

