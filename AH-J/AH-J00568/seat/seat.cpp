#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[103],b[103],n,m,a1,k1,n1,m1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
	a1=a[0];
	sort(a,&a[n*m]);
	for(int i=0,j=n*m-1;i<n*m;i++,j--){
		b[i]=a[j];
		if(b[i]==a1)k1=i;
	}
	n1=k1/n+1;
	if(n1%2)m1=k1%n+1;
	else m1=n-k1%n;
	printf("%d %d",n1,m1);
	return 0;
}
