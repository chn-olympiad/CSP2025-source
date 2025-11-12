#include<bits/stdc++.h>
using namespace std;
long long n,m,r;
long long a[105];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.out","w",stdout);
	freopen("seat.in" ,"r",stdin );
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(a[(i-1)*m+j]==r){
				if(i%2)printf("%lld %lld",i,j);
				else printf("%lld %lld",i,n-j+1);
				return 0;
			}
	}
	return 0;
}

