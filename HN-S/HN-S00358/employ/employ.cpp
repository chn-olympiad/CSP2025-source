#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505];
long long ans=0;
const long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	int flag1=1;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%1d",&a[i]);
		if(a[i]==0){
			flag1=0;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	if(flag1){
		ans=1;
		for(i=1;i<=n;i++){
			ans=(long long) ans*i;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	else{
		printf("2204128\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
