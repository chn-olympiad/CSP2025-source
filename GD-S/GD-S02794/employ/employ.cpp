#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000005],now,b=998244353;
bool ok;
char s[1000005];
long long qu(long long pos){
	if(pos==0)return 1;
	long long ans=1;
	for(long long i=1;i<=pos;i++){
		ans*=i;
		ans%=b;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	now=n;
//	for(long long i=0;i<n;i++)if(s[i]=='0')ok=1;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0)now--;
	}
	if(now<m){
		printf("0");
		return 0;
	}
	long long sum=(qu(now)%b)*(qu(n-now)%b)%b;
	printf("%lld",sum);
	return 0;
}
