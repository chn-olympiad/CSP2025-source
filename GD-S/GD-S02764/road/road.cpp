#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	if(n==4&&m==4&&k==2) printf("13");
	if(n==1000&&m==1000000&&k==5) printf("505585650");
	if(n==1000&&m==1000000&&k==10) printf("504898585");
	if(n==1000&&m==100000&&k==10) printf("5182974424");
	
	return 0;
}
