#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int a[MAXN*MAXN];
int main() {
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int R;
	for(int i = 0; i<n*m; i++) {
		if(i==0) {
			scanf("%d",&R);
			a[0]=R;
		} else scanf("%d",&a[i]);
	}
	for(int i = 0;i<n*m;i++){
		for(int j = i+1;j<n*m;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	if (R==a[m*n-1]){printf("%d %d",n,m);
	return 0;
	}
	for(int i = 0; i<n*m; i++) {
		if(R==a[i]) {
			printf("%d ",i/n+1);
			if(((i/n+1)%2)==1)printf("%d",i%n+1);
			else printf("%d",m-i%n);
			return 0;
		}
	}
	return 0;
}