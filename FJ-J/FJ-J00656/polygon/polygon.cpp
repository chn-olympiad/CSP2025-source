#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],maxx;
long long ans,anss=1,aans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=false;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[1]){
			flag=true;
		}
	}
	if(n<3)printf("0");
	if(n==3){
		maxx=max(a[1],max(a[2],a[3]));
		if(maxx*2<a[1]+a[2]+a[3]){
			printf("1");
		}
		else printf("0");
	}
	else if(!flag){
		aans=6;
		for(int i=n;i>n-3;i--){
			anss=anss*i%mod;
		}
		ans=(ans+anss/aans)%mod;
		for(int i=4;i<=n;i++){
			aans=aans*i%mod;
			anss=anss*(n-i+1)%mod;
			ans=(ans+(anss/aans))%mod;
		}
		printf("%lld",ans);
	}
	else{
		printf("0");
	}
	return 0;
}
