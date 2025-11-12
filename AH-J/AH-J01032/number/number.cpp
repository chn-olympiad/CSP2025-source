#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[1000001];
	int b,c[10];
	for(int i=0;i<=9;i++){
		c[i]=0;
	}
	int sum=0;
	cin>>a;
	for(int i=0;i<100001;i++){
		b=int(a[i]);
		if(b>=48 and b<=57){
			c[b-48]+=1;
			sum+=1;
		}
		else if(b>=97 and b<=122){
			1;
		}
		else{
			break;
		}
	}
	for(int i=9;i>=0;i--){
		for(int x=0;x<c[i];x++){
			cout<<i;
		}
	}
	return 0;
}
