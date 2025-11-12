#include<bits/stdc++.h>
using namespace std;
int n,m,p=1,w,k;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&w);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&k);
		if(k>w) p++;
	}
	c=(p-1)/n+1;
	if(c%2==1){
		r=p-(c-1)*n;
	}else{
		r=n-(p-(c-1)*n)+1;
	}
	printf("%d %d",c,r);
	return 0;
} 
