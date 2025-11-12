#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,c[501],i,p[501],x,f,r,ans;
char s[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(i=0;i^n;++i)scanf("%d",c+i);
	for(i=0;i^n;++i)p[i]=i;
	do{
		f=r=0;
		for(i=0;i^n;++i)s[p[i]]=='1'&&f<c[p[i]]?++r:++f;
		if(r>=m)++ans;
	}while(next_permutation(p,p+n));
	printf("%d",ans);
	return 0;
}
