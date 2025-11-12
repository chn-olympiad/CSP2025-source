#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,mv,a[10005];
bool cmp(int c,int b){
	return c>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			mv=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mv){
			y=i%n==0?i/n:i/n+1;
			i-=(y-1)*n;
			if(y%2==0){
				x=n-i+1;
			}
			else{
				x=i;
			}
			break;
		}
	} 
	printf("%d %d",y,x);
	return 0;
} 

