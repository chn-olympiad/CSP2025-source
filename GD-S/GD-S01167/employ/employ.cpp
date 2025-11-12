#include<bits/stdc++.h>
using namespace std;
int n,m,s[501],c[501];
char ch;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%c",&ch);
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	printf("%s","T^T");
	return 0;
}
