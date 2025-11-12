#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5];
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	int maxn=max(a[0],a[1]);
	maxn=max(maxn,a[2]);
	if(maxn*2<a[0]+a[1]+a[2]){
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
} 