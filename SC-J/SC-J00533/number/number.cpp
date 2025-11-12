#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a{}；
	int b{}=0;
	int n=0;
	cin>>a;
	for(int i=0;i<=a;i++){
		if(a[i]>=1 and a[i]<=9){
			a[i]=b[n];
			n++;
		}
	} 
	for(int i=0;i<=b;i++){
		if(b[i+1]>b[i]){
			b[i]=b[i+1];
		}
	}
	cout<<b;
	return 0;
}