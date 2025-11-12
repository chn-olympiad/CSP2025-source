#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,pm;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<n*m;i++){
		int tmp;
		scanf("%lld",&tmp);
		if(tmp>k)pm++;
	}
	int k=pm/n+1;
	int w;
	if(k&1)w=pm%n+1;
	else w=m-(pm%n);
	printf("%lld %lld",k,w);
	return 0;
}
