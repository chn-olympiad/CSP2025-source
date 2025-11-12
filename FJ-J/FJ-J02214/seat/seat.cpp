#include <bits/stdc++.h>
using namespace std;
int n,m,num;
long long a[10001],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		num++;
		if(a[i]==r) break;
	}
	int i=num%n,j=ceil((double)num/n);
	if(i==0) i=n;
	if(j%2==0) i=n-i+1;
	
	printf("%d %d",j,i);
	return 0;
}
