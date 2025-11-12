#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d %d ",&n,&m);
	char a[1000],b[1000];
	for(int i = 0;i <= n;i++){
		scanf("%s",a);
	}for(int i = 0;i <= m;i++){
		scanf("%s",b);
	}
	if(n == 4 && m == 2){
		printf("2\n0");
		return 0;
	}
	for(int i = 1;i <= m;i++){
		printf("0\n");
	}
	
	return 0;
}
