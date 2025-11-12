#include<bits/stdc++.h>
using namespace std;
int n,m,x,idx;
bool cmp(int p,int q){
	return p>q;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int a[n*m+5]={0};
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			idx=i;
			break;
		}
	}
	if(idx%n==0){
		printf("%d ",idx/n);
		if((idx/n)%2==1){
			printf("%d",n);
		}
		else printf("1");
	}
	else{
		printf("%d ",idx/n+1);
		if((idx/n+1)%2==1){
			printf("%d",idx%n);
		}
		else printf("%d",n-(idx%n)+1);
	}
	return 0;
}
