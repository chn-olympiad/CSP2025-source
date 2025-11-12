#include<bits/stdc++.h>
using namespace std;
int n,m,p[102],t,l,kk;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p[1]);
	t=p[1];
	for(int i=2;i<=n*m;i++) {
		scanf("%d",&p[i]);
	}
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=m*n;i++)
		if(p[i]==t) {l=i;  break;}
	printf("%d",(l+n-1)/n);
	if(((l+n-1)/n)%2!=0) {
		if(l%n!=0)
		printf(" %d",l%n);
		else printf(" %d",n);
	}
	else printf(" %d",n-(l-1)%n);
	return 0;
}
