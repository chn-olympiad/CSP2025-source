#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s,c;long long ans=1; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	printf("%lld",ans);
	return 0;
}
