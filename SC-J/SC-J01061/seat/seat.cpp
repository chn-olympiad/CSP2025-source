#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int grade,a1,j=1;
	scanf("%d",&a1);
	a[a1]=1;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&grade);
		a[grade]=1;
		if(grade>a1){
			j++;
		}
	}
	int a1m=j/n+1,a1n;
	if(a1m%2==1){
		if(j%n==0) a1n=n;
		else a1n=j%n;
	}else{
		if(j%n==0) a1n=1;
		else a1n=n-j%n+1;
	}
	printf("%d %d",a1m,a1n);
	return 0;
}