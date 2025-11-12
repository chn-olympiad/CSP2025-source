#include<bits/stdc++.h>
using namespace std;
const int MAXN=207;
long long c,r,a[MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&c,&r);
	for(int i=1;i<=r*c;i++){
		scanf("%lld",&a[i]);
	}
	long long k=a[1],p=0;
	sort(a+1,a+r*c+1,greater<long long>());
	for(int i=1;i<=c;i++){
		if(i%2==1)
			for(int j=1;j<=r;j++){
				p++;
				if(a[p]==k){
					printf("%d %d",i,j);
					return 0;
				}
			}
		else if(i%2==0)
			for(int j=r;j>=1;j--){
				p++;
				if(a[p]==k){
					printf("%d %d",i,j);
					return 0;
				}
			}
	}
	//priority
	return 0;
}
