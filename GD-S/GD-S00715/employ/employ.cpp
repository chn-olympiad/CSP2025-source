#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int m,n,c[505],sum;
char har[1005];
string line;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getline(cin,line);
	for(int i=1;i<=n;sum+=har[i]-'0',i++) har[i]=getchar();
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if((sum<m)||(n==m&sum<n)){
		printf("0");
		return 0;
	}
	long long ans=1ll;
	for(int i=n;i>=2;i++){
		ans*=1ll*i;
		ans%=1ll*mod;
	}
	printf("%lld",ans);
	return 0;
}
