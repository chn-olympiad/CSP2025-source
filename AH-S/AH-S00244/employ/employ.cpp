#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j;
char s[505];
long long c[505],mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(m==n){
		long long flag=0;
		for(i=1;i<=n;i++){
			if(s[i]=='0'){
				flag=1;
				break;
			}
			if(c[i]==0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("0\n");
		}else{
			long long ans=1;
			for(i=n;i>=1;i--){
				ans=ans*i%mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
