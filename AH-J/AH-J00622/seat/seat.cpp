#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL a[110];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	LL n,m;
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	LL x=a[1],num;
	sort(a+1,a+n*m+1,cmp);
	for(LL i=1;i<=n*m;i++){
		if(a[i]==x) num=i;
	}
	LL t=0;
	for(LL j=1;j<=m;j++){
		if(j%2!=0){
			for(LL i=1;i<=n;i++){
				t++;
				if(t==num){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else if(j%2==0){
			for(LL i=n;i>=1;i--){
				t++;
				if(t==num){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
