#include<bits/stdc++.h>
using namespace std;
const int A1=109;
int a[A1],a1,a2,a3,a4,a5;
bool A2(int c1,int c2){
	return c1>c2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&a1,&a2);
	scanf("%d",&a3);
	a[1]=a3;
	for(int b1=2;b1<=a1*a2;b1++){
		scanf("%d",&a[b1]);
	}
	sort(a+1,a+a1*a2+1,A2);
	for(int b1=1;b1<=a1*a2;b1++){
		if(a[b1]==a3){
			a3=b1;
		}
	}
	for(int b1=1;b1<=a1;b1++){
		if(b1%2==0){
			for(int b2=a2;b2>=1;b2--){
				a3--;
				if(a3==0){
					printf("%d %d",b1,b2);
				}
			}
		}
		else{
			for(int b2=1;b2<=a2;b2++){
				a3--;
				if(a3==0){
					printf("%d %d",b1,b2);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
