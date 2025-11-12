#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],xm;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	xm=a[0];
	sort(a,a+n*m);
	int net=0;
	for(int i=m;i>0;i--){
		if(i%2==1){
			for(int j=n;j>0;j--){
				if(xm==a[net]){
					printf("%d %d",i,j);
					return 0;
				}
				net++;
			}
		}
		if(i%2==0){
			for(int j=1;j<=n;j++){
				if(xm==a[net]){
					printf("%d %d",i,j);
					return 0;
				}
				net++;
			}
				
		}
	}
	return 0;
}
