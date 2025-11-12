#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][5],b[100010],c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(long long o=0;o<t;o++){
		scanf("%lld",&n);
		for(long long i=0;i<n;i++){
			for(long long j=0;j<3;j++){
				scanf("%lld",&a[i][j]);	
			}
		}
		sort(b,b+n);
		for(long long i=n-1;i>=n/2;i--) c+=b[i];
		printf("%lld",c);
	}
	return 0;
} 
