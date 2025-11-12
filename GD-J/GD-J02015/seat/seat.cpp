#include<bits/stdc++.h>
using namespace std;
long long a[15][15],ans,n,m,seat[105],cnt=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%lld",&seat[i]);
	}
	ans=seat[1];
	sort(seat+1,seat+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(long long i=1;i<=n;i++){
				cnt++;
				if(seat[cnt]==ans){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(long long i=n;i>=1;i--){
				cnt++;
				if(seat[cnt]==ans){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
