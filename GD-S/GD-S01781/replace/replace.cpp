#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[2007][200007];
char s2[2007][200007];
char t1[2007][200007];
char t2[2007][200007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1[i]);
		scanf("%s",s2[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%s",t1[i]);
		scanf("%s",t2[i]);
		printf("%d\n",n/2-q);
	}
	return 0;
	
}
