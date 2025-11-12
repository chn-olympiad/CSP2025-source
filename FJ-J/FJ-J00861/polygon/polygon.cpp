#include <bits/stdc++.h>
using namespace std;
int n,s,maxx=-1;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		maxx=max(maxx,a[i]);
	}
	if (n==3){
		if (s>2*maxx) printf("1\n");
		else printf("0\n");
		return 0;
	}
	else printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
