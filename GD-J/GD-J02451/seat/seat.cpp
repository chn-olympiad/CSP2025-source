#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,h,l,pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=1;i<n*m;i++){
		scanf("%d",&b);
		if(b>a)pm++;
	}
	if(((pm-1)/n+1)&1)printf("%d %d",(pm-1)/n+1,(pm%n==0)?n:pm%n);
	else printf("%d %d",(pm-1)/n+1,n-((pm%n==0)?n:pm%n)+1);
	return 0;
} 
