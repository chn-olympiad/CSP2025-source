#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1;
int a,a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&a1);
	for(int i=1;i<n*m;i++){
		scanf("%d",&a);
		if(a>a1){
			if(x%2==1){
				y++;
				if(y>n){
					y=n;
					x++;
				}
			}
			else if(x%2==0){
				y--;
				if(y<1){
					y=1;
					x++;
				}
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
