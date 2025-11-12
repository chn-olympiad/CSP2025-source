#include<iostream>
using namespace std;
int a[9];
int main(){
    freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	char n;
	for(int j=0;j<1000000;j++){
		n=getchar();
		if(n==EOF)break;
		if(n-'0'>=0&&n-'0'<=9){
			a[n-'0']++;
		}
	}	
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}