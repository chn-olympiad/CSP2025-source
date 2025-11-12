#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102],a1;
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	a1=a[1];
	return;
}
int p;
int l,r;
void work(){
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m*n;i++){
		if(a[i]==a1){
			p=n*m-i+1;
			break;
		}
	}
	l=(p+n-1)/n;
	r=p%n;
	if(r==0)r=n;
	if(l%2==0){
		r=n+1-r;
	}
	printf("%d %d",l,r);
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t;
	//~ scanf("%d",&t);
	t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
