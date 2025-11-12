#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct wl{
	int s,num;
}a[105];
bool cmp(wl x,wl y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].s);
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			cnt=i;
			break;
		}
	}
	int c;
	if(cnt%n==0){
		c=cnt/n;
	}else{
		c=cnt/n+1;
	}
	int r,b;
	if(cnt%n==0){
		b=n;
	}else{
		b=cnt%n;
	}
	if(c%2){
		r=b;
	}else{
		r=n-b+1;
	}
	printf("%d %d",c,r);
	return 0;
}
