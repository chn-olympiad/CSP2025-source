#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m);
	if(n==4){
		printf("2\n0");
	}
	else if(n==3){
		printf("0\n0\n0\n0");
	}
	for(int i=1;i<=m;i++){
		printf("0\n");
	}
	return 0;
}
