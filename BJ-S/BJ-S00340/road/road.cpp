#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,u,w[1000005];
long long num;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&v,&u,&w[i]);
	}
	sort(w+1,w+1+m);
	for(int i=1;i<=n;i++){
		num+=w[i];
	}
	printf("%lld",num);


	return 0;
}
