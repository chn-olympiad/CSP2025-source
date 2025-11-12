#include<stdio.h>
int n,m,s[501],cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%1d",&s[i]);
		if(s[i]==1)++cnt;
	}
	printf("%d",cnt);
}
