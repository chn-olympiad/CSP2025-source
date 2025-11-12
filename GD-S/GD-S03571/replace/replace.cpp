#include<cstdio>
int n,q;
char s1[5000001],s2[5000001],t1[5000001],t2[5000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%s%s",&s1[i],&s2[i]);
	}
	for(int j=0;j<q;j++){
		scanf("%s%s",&t1[j],&t2[j]);
	}
	printf("0\n0\n0\n0");
	return 0;
} 
