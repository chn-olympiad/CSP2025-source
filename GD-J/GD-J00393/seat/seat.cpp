#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&a,&b,&d);
	for(int z=1;z<a*b;z++){
		scanf("%d",&c);
		if(c>d)e++;
	}
	if(e%a==0){
		if(e/a%2)printf("%d %d",e/a,a);
		else printf("%d %d",e/a,1);
	}
	else{
		if(e/a%2==0)printf("%d %d",e/a+1,e%a);
		else printf("%d %d",e/a+1,a-e%a+1);
	}
	return 0;
}
