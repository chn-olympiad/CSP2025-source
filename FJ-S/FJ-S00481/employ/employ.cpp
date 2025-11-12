#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],p[505],ans,f[20][(1<<18)+5];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf(" %c",&s[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]),p[i]=i; 
	do{
		int cnt=0;
		for (int i=1;i<=n;i++) if (s[i]=='0'||cnt>=c[p[i]]) cnt++;
		if (n-cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d\n",ans);
	return 0;
}
