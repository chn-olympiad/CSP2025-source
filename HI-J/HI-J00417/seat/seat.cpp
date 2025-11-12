#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],xr;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
	}
	xr=s[1];
	sort(s+1,s+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==xr){
			if((i+(n-1))/n%2==0){
				if(i%n!=0){
					printf("%d %d",(i+(n-1))/n,n-(i%n)+1);
				}else{
					printf("%d %d",(i+(n-1))/n,1);
				}
				return 0;
			}else{
				if(i!=n){
					printf("%d %d",(i+(n-1))/n,i%n);
				}else{
					printf("%d %d",(i+(n-1))/n,n);
				}
				return 0;
			}
		}
	}
	return 0;
}
