#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001],x,u;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			u=n*m-i+1;
			break;
		}
	}
	if(u%n==0){
		if((u/n)%2==1)
			printf("%d %d",u/n,n);
		else
			printf("%d %d",u/n,1);
		return 0;
	}
	if((u/n)%2==0)
		printf("%d %d",u/n+1,u%n);
	else
		printf("%d %d",u/n+1,n-u%n+1);
	return 0;
} 
