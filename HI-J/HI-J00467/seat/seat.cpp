#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n*m;i++){
		scanf("%lld",&a[i]);
	}
	long long sum=a[0];
	sort(a,a+n*m);
	long long k=n*m-1;
	for(long long i=0;i<m;i++){
		if(i%2==0){
			for(long long j=0;j<n;j++){
				if(a[k]==sum){
					printf("%lld %lld",i+1,j+1);
					return 0;
				}
				k--;
			}
		}else{
			for(long long j=n-1;j>=0;j--){
				if(a[k]==sum){
					printf("%lld %lld",i+1,j+1);
					return 0;
				}
				k--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
