#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int rk,r,c;
int val[N+5],a[N+5];
bool cmp(int x,int y){
	return val[x]>val[y];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&val[i]);
		a[i]=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==1){
			rk=i;
			break;
		}
	c=(rk-1)/n+1;
	if(c&1)
		r=rk-(c-1)*n;
	else r=n-(rk-(c-1)*n)+1;
	printf("%d %d",c,r);
	return 0;
}

