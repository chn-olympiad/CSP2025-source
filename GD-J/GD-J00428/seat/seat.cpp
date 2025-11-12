#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[105],cnt;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=(n*m);i++){
		scanf("%lld",&a[i]);
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				++cnt;
				if(a[cnt]==R){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				++cnt;
				if(a[cnt]==R){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
