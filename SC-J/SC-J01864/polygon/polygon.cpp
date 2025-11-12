#include<bits/stdc++.h>
using namespace std;
int a[5005],g[5005],mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		g[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(n<3) printf("0\n");
	else if(n==3){
		if(a[1]+a[2]>a[3]) printf("1\n");
		else printf("0\n");
	}
	else{
		long long now=n*(n-1)*(n-2)/6;
		int ans=now;
		for(int i=3;i<n;i++) now=now*(n-i)/(i+1)%mod,ans=(ans+now)%mod;
		printf("%d\n",ans);
	}
	return 0;
}