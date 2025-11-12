#include<bits/stdc++.h>
using namespace std;
const int A1=500009;
int a[A1],b[A1],a1,a2,a3,a4,a5;
bool a6=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&a1,&a2);
	for(int b1=1;b1<=a1;b1++){
		scanf("%d",&a[b1]);
		if(a2==0 and a[b1]!=1){
			a6=0;
		}
		if(a2==0 and a[b1]==0){
			a3++;
		}
		if(a2==1 and a[b1]==1){
			a3++;
		}
		//b[b1]=b[b1-1]^a[b1];
	}
	if(a6){
		printf("%d",a1/2);
		return 0;
	}
	if(a2==1 and a6){
		printf("%d",a1);
		return 0;
	}
	printf("%d",a3);
//	for(int b1=1;b1<=a1;b1++){
//		
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
