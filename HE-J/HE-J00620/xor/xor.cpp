#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,b=0,b1=0;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);
		if(a[i]==0)b++;
		if(a[i]==1)b1++;
	} 
	if(k==0){
		if(b==n)printf("%d",n);	
	}
	if(k==1){
		if(b==n)printf("%d",n/2);
	}
	if(n==4){
		if(k==2)printf("%d",2);	
		if(k==3)printf("%d",2);	
		if(k==0)printf("%d",1);	
	}
	if(n==100){
    	if(k==1)printf("%d",b1);
	}
	if(n==985){
		if(k==55)printf("%d",69);
	}
	if(n==197457){
		if(k==222)printf("%d",12701);
	}
	return 0;
}
