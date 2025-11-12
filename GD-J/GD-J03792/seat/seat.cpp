#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],s[105][105],k,cnt;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=m;i++){
		if(i%2==1){
			for(long long j=1;j<=n;j++){
				s[j][i]=a[++cnt];
			}
		}
		else{
			for(long long j=n;j>=1;j--){
				s[j][i]=a[++cnt];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(s[i][j]==k){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
