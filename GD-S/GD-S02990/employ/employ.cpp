#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,m,c[N],p[N],ans;char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i(1);i<=n;++i) scanf(" %c",&s[i]);
	for(int i(1);i<=n;++i) scanf("%d",&c[i]);
	for(int i(1);i<=n;++i) p[i]=i;
	do{
		int cnt(0);
		for(int i(1);i<=n;++i)
			cnt+=(s[i]=='0'||cnt>=c[p[i]]);
		if(n-cnt>=m) ++ans;
	} while(next_permutation(p+1,p+1+n));
	printf("%d\n",ans);
	return 0;
}
