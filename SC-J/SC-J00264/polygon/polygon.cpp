#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int mx=0,sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	if(n<3){
		printf("0");
		return 0;
	}
	if(sum>mx*2) printf("1");
	else printf("0");
	return 0;
}