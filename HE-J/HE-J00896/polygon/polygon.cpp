#include<bits/stdc++.h>
using namespace std;
int n,maxb;
long long ans;
int a[5005],b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]*2;
		maxb=max(maxb,b[i]);
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		if(ans<=maxb) ans=0;
		else ans=1;
	}
	ans=ans%998%244%353;
	printf("%lld",ans);
	return 0;
} 
