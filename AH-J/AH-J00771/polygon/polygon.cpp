#include<stdio.h>
#include<algorithm>
int n,bian[5002];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&bian[i]);
	std::sort(bian+1,bian+n+1);
	if(n==3) {
		if(bian[1]+bian[2]>bian[3])printf("1");
		else printf("0");}
	return 0;
}
