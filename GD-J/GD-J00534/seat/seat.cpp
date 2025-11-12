#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],t,i,c,r;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m*n;++i){
		scanf("%lld",&a[i]);
	}
	t=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(i=1;i<=m*n && a[i]!=t;++i);
	c=i/n;
	if(i%n!=0)	c++;
	r=i%n;
	if(r==0)	r=n;
	if(c%2==0)	r=n-r+1;
	printf("%lld %lld",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
