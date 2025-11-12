#include<bits/stdc++.h>
using namespace std;
int n,m,h,l;
struct seat{
	int s;
	bool r;
}a[110];
bool cmp(seat x,seat y){
	if(x.s>y.s) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].s);
		if(i==1) a[i].r=1;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].r==1){
			l=i/n;
			if(i%n) l+=1;
			h=i%(2*n);
			if(h==0) h=1;
			if(h>n) h=2*n+1-h;
			break;
		}
	}
	printf("%d %d",l,h);
	return 0;
}