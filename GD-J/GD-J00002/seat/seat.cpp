#include<bits/stdc++.h>
using namespace std;
int n,m,s[110]={0},c=0,r=0,cr=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
		if(s[i]>s[1]) cr++;
	}
	if(cr%n==0){
		c=cr/n;
		cr%=n;
		if(c%2==0) r=1;
		else r=n;
	}else{
		c=cr/n+1;
		cr%=n;
		if(c%2==0) r=n-cr+1;
		else r=cr;
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
