#include<bits/stdc++.h>

using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n*m+10];
	for(int i=1;i<=n*m;++i) scanf("%d",&a[i]);
	int R=a[1];
	sort(a,a+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;++i) 
		if(a[i]>R) ++cnt;
	int c,r;
	c=cnt/n+1;
	if(c%2==0) r=n-cnt%n;
	else r=cnt%n+1;
	printf("%d %d",c,r);
	return 0;
}