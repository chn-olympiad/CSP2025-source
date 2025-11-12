#include<bits/stdc++.h>
using namespace std;
struct se{
	int s,n;
} a[105];
int n,m;
bool cmp(se b,se c){
	return b.n>c.n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].n);
		a[i].s=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].s==1){
			int d=i/m+(i%m!=0);
			printf("%d ",d);
			if(d%2==0){
				if(i%m==0)printf("1");
				else printf("%d",n-(i%m)+1);
			}else{
				if(i%m==0)printf("%d",n);
				else printf("%d",i%m);
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

