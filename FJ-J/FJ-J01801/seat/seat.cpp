#include <bits/stdc++.h>
using namespace std;
int m,n;
int a1,ai,pm=1;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a1);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&ai);
		if(ai>=a1)pm++;
	}
	if(pm%n==0){
		c=pm/n;
	}
	else{
		c=pm/n+1;
	}
	if(c%2==1){
		if(pm%n==0){
			r=n;
		}
		else{
			r=pm%n;
		}
	}
	else{
		if(pm%n==0){
			r=1;
		}
		else{
			r=n-pm%n+1;
		}
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
