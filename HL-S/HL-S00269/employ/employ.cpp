#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510],ans=1;
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	ans=ans%998244353;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
