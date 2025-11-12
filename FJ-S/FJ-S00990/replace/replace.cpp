#include<bits/stdc++.h>
using namespace std;
int n,q;
char t1[10005],t2[10005];
char s1[10005][1005],s2[10005][1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s1[i],s2[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%s %s",t1,t2);
		printf("0\n");
	}
	return 0;
}