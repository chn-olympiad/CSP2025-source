#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int ans=1;
char s[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",&s);
	for(int i=1;i<=n;i++){
		ans = ((ans%998244353)*i)%998244353;
	}
	printf("%lld",ans);
	return 0;
} 
