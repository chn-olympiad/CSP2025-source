#include <bits/stdc++.h>
using namespace std;
int n,m,c[1000];
string s;
long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=n;i>=1;--i)sum=(sum*n)%998244353;
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
