#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",a+i);
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			printf("%d ",(i-1)/n+1);
			if(((i-1)/n+1)%2){
				printf("%d",(i-1)%n+1);
			}else{
				printf("%d",n-(i-1)%n);
			}
			return 0;
		}
	}
}