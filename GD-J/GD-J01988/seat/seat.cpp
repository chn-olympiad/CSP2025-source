#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m,cnt,c,r;
int a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&b);
		cnt+=(int)(b>a);
	}
	c=cnt/n+1;
	if(c%2==1){
		r=cnt%n+1;
	} else {
		r=n-(cnt%n);
	}
	printf("%d %d",c,r);
	return 0;
}
