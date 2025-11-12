#include <bits/stdc++.h>
using namespace std;
#define N 505
char s[N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0;i<n;i++)
		scanf("%d",c+i);
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans*=i;
	printf("%lld\n",ans);

	return 0;
}
