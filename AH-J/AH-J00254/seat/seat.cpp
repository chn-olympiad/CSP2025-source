#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<n*m;i++){
		scanf("%d",&a);
		if(a>x) s++;
	}
	if(s/n%2) printf("%d %d",s/n+1,n-s%n);
	else printf("%d %d",s/n+1,s%n+1);
	return 0;
}
