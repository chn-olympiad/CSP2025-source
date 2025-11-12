#include <bits/stdc++.h>
using namespace std;
struct node{
	int r,num;
}a[105];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0,tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].num);
		if(a[i].num==i) sum++;
		if(a[i].num==n*m-i+1) tot++;
	}
	if(sum==n*m){
		if(m%2==1){
			printf("%d %d",m,n);
		}
		else printf("%d 1",m);
		return 0;
	}
	if(tot==n*m){
		puts("1 1");
		return 0;
	}
	a[1].r=1;
	sort(a+1,a+n*m+1,cmp);
	int pos=1;
	for(pos=1;pos<=n*m;pos++){
		if(a[pos].r==1) break;
	}
	int x=pos/n,cnt=pos%n;
	if(cnt==0){
		if(x%2==1) printf("%d %d",x,n);
		else printf("%d 1",x);
	}
	else{
		x++;
		if(x%2==1) printf("%d %d",x,cnt);
		else printf("%d %d",x,n-cnt+1);
	}
	return 0;
}
