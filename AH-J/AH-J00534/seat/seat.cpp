#include<bits/stdc++.h>
using namespace std;
long long m,n,a[110],rs,t=0;
bool cmp(const long long &x,const long long &y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&m,&n);
	for(long long i=1;i<=m*n;i++) scanf("%lld",&a[i]);
	rs=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(long long i=1;i<=n;i++)
		if(i%2==1)
			for(long long j=1;j<=m;j++){
				t++;
				if(a[t]==rs){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		else 
			for(long long j=m;j>=1;j--){
				t++;
				if(a[t]==rs){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
	return 0;
}
