#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,r,n,m,num,R;
ll a[1234567],s[150][150];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll x=n*m;
	for(int i=1;i<=x;i++){
		scanf("%lld",&a[i]);
	}
	R=a[1];
	sort(a+1,a+1+x);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1){
				if(a[x]==R){
					printf("%d %d",j,i);
					return 0;
				}
				s[i][j]=a[x];
				x--;
			}
			if(i%2==0){
				for(int j=m;j>=1;j--){
					if(a[x]==R){
						printf("%d %d",j,i);
						return 0;
					}
					s[i][j]=a[x];
					x--;
				}
				i++;
			}
		}
	}
	return 0;
}
