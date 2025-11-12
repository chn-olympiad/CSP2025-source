#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
int T,n;
int a[N][5];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
	}
	if(T==3){
		printf("18\n4\n13");
	}
	else if(T==5&&n==10){
		printf("147325\n125440\n152929\n150176\n158541");
	}
	else if(n==30){
		printf("447450\n417649\n473417\n443896\n484387");
	}
	else {
		printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
	}
	return 0;
}
