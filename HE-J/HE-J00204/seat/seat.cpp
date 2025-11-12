#include<bits/stdc++.h>
using namespace std;

int n,m,a[200],x;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]){
			x++;
		}
	}
	int y=x/n+1,z=x%n+1;
	if(!(y%2)){
		z=m-z+1;
	}
	printf("%d %d",y,z); 
	return 0;
} 
