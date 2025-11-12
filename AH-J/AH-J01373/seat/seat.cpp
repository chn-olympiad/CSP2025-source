#include<bits/stdc++.h>
using namespace std;
int a[10005],c,r,n,s=0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&c,&r);
	n=c*r;
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i] > a[1]) s++; 
	}
	s++;
	for(int i=1;;i++) {
		if(s-c > 0) s-=c;
		else {
			if(i%2 == 1) {
				printf("%d %d",i,s);
			}
			else {
				printf("%d %d",i,c-s+1);
			}
			return 0;
		}
	}
}
