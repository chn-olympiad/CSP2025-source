#include<bits/stdc++.h>
using namespace std;
int x,y,z,c[105],r,a,b0,b1;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	scanf("%d %d",&x,&y);
	z=x*y;
	for(int i=0;i<z;i++){
		scanf("%d",&c[i]);
	}
	r=c[0];
	sort(c,c+z);
	a=lower_bound(c,c+z,r)-c;
	a=z-a-1;
	b0=a/y+1;
	b1=a%y;
	if(b0%2==1){
		printf("%d %d",b0,b1+1);
	}else{
		printf("%d %d",b0,y-b1);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
