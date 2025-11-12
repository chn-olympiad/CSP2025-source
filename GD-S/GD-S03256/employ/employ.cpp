#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n,m,s[N],c[N],p[N],tot,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%1d",&s[i]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]),p[i]=i;
	do{
		tot=0;
		for(int i=1;i<=n;++i)
			if(i-1-tot<c[p[i]]&&s[i]) ++tot;
		if(tot==m) ++ans;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
} 
