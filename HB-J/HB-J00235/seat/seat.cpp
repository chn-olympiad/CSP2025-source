#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	for(int i=2;i<=n*m;++i){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) ++cnt;
	}
	c=cnt/n;
	if(cnt%n==0) printf("%d %d",c,n);
	else{
		++c;
		c%2?r=cnt%n:r=n-cnt%n+1;
		printf("%d %d",c,r);
	}
	return 0;
}
