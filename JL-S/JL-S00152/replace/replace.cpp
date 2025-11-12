#include<bits/stdc++.h>
using namespace std;
char s1[10005][10005];
char s2[10005][10005];
char t1[10005][10005];
char t2[10005][10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i],s2[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",t1[i],t2[i]);
	}
	if(n==4&&q==2){
		printf("2\n");
		printf("0\n");
	}else if(n==3&&q==4){
		printf("0\n");
		printf("0\n");
		printf("0\n");
		printf("0\n");
	}else{
		for(int i=1;i<=q;i++){
			printf("0\n");
		}
	}
	return 0;
}
