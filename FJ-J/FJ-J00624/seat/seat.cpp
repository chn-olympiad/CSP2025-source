#include<bits/stdc++.h>
using namespace std;
int m,n,a,b,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&b);
		if(b>a){
			++cnt;
		}
	}
	if((cnt+n-1)/n%2==0){
		if(cnt%n==0){
			printf("%d %d",(cnt+n-1)/n,1);
		}else{
			printf("%d %d",(cnt+n-1)/n,n-(cnt%n)+1);
		}
	}else{
		if(cnt%n==0){
			printf("%d %d",(cnt+n-1)/n,n);
		}else{
			printf("%d %d",(cnt+n-1)/n,cnt%n);
		}
	}
	return 0;
}
