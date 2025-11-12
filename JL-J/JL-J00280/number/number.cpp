#include<bits/stdc++.h>
using namespace std;
int b[1000050];
int main(){
	long long int a,i=1;
	scanf("%d",&a);
	while(a>0){
		b[i]=a%10;
		a=a/10;
		i++;
	}
	sort(b+1,b+i+1);
	for(;i<=1;i--){
		printf("%d",b[i]);
	}
	return 0;
		
		
