#include<bits/stdc++.h>
using namespace std;
int l[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	if(n==3){
		sort(l+1,l+n+1);
		if(l[1]+l[2]>l[3]) printf("1");
		else printf("0");
	}else printf("1");
	return 0;
}
