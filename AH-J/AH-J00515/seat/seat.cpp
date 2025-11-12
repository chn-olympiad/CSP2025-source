#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m=0,n=0;
    scanf("%d%d",&n,&m);
    int score=0,x=0,pos=1;
    scanf("%d",&score);
    for (int i=n*m;i>1;i--){
		scanf("%d",&x);
		if (score < x) pos++;
	}
    int c=(pos-1)/n+1,r=pos%n;
	if (r==0) r=n;
	if (c%2==0) r=n+1-r;
	printf("%d %d\n",c,r);
    return 0;
}



