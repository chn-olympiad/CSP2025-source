#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])printf("1");
		else printf("0");
	}
	else{
		if(sum>a[n]*2)ans++;
		ans+=n*2;
		ans%=998244353;
		printf("%d",ans);
	}
	return 0;
}
