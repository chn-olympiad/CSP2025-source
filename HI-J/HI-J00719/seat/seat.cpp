#include <iostream>
int main(){
	int n=2;
	int m=2;
	int a[]={99,100,97,98};
	for(int i=0;i<2;i++){
		if(a[i]<a[i+1]){
			a[i+1]=a[i];
		}
	}
	int c=1;
	int l=2;
	std::cout<<c<<' '<<l;
}
