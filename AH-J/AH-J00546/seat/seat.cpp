#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=105;
LL n,m,R,a[N];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)R=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	LL num=0;
	for(LL i=1;i<=m;i++){  //列
		if(i%2==1){
			for(LL j=1;j<=n;j++){
				if(a[++num]==R){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(LL j=n;j>=1;j--){
				if(a[++num]==R){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
