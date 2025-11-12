#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0; 
	}for(int i=2;i<=n*m;i++){
		scanf("%d",&x);
		if(x>a) num++;
	}int c=(num-1)/n+1;
	num-=(c-1)*n;
	printf("%d ",c);
	if(c%2==1) printf("%d",num);
	else printf("%d",n-num+1);
	return 0;
}