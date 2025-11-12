#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,v[100005],ansx,ansy;
bool cmp(long long A,long long B){
	return A>B;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++)scanf("%lld",&v[i]);
	sum=v[1];
	sort(v+1,v+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(v[i]==sum){
			ansy=(i-1)%n+1;
			ansx=(i-1)/n+1;
			if(ansx%2==0){
				ansy=n-ansy+1;
			}
			break;
		}
	}
	printf("%lld %lld",ansx,ansy);
	return 0;
}
