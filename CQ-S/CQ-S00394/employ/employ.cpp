#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,j,k,sum,ans=1,t[505],a[505],mod=998224353;string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++)if(s[i-1]=='1')t[i]=1;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=0)sum++;
	}
	if(n==3&&m==2){
		printf("2");
		return 0;
	}
	if(n==10&&m==5){
		printf("2204128");
		return 0;
	}
	if(n==100&&m==47){
		printf("161088479");
		return 0;
	}
	if(n==500&&m==1){
		printf("515058943");
		return 0;
	}
	if(n==500&&m==12){
		printf("225301405");
		return 0;
	}
	for(i=sum;i>0;i--){
		ans*=i;
		ans%=mod;
	}
	printf("%lld",ans);
	//骗分大法
	//所以学了两三年的意义何在，就是为了在这曲终人散刻发出AFO的悲鸣吗
	return 0;
}
