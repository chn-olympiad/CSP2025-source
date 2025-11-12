#include<bits/stdc++.h>
using namespace std;
int n,m,s=1,a[105],l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int c=n*m;
	for(int i=1;i<=c;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=100;i>=1;i--){
			if(a[1]==i){
				if(s%n==0){
					l=s/n;
				}
				else{
					l=(s+n)/n;
				}
				if(l%2==0){
					if(s%n==0){
						h=1;
					}
					else{
						h=n-(s%n)+1;
					}
				}
				else{
					if(s%l==0){
						h=s/l;
					}
					else{
						h=s%n;
					}
				}	
				printf("%lld %lld",l,h);
				return 0;
			}
		for(int j=2;j<=100;j++){
			if(a[j]==i){
				s++;
			}
		}
	}
	return 0;
}
