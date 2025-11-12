#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,uns[110],a[20][20],ans[20][20];
ll cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",n,m); 
	ll tot=n*m;
	for(int i=0;i<tot;i++){
		scanf("%lld",a[i]);
	}
	ll target=uns[0];
	sort(uns,uns+tot,cmp);
	for(int i=0;i<tot;i++){
		a[i%n][i/n]=uns[i];
	}
	for(int j=0;j<m;j++){
		if(j%2==0){
			for(int i=0;i<n;i++){
				ans[i][j]=a[i][j];
			}
		}
		if(j%2==1){
			for(int i=0;i<n;i++){
				ans[i][j]=a[n-i-1][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]==target){
				printf("%lld %lld",j+1,i+1);
				exit(0);
			}
		}
	}
	return 0; 
}
