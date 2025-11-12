#include<iostream>	
int main(){	
	std::string s;
	std::cin>>s;
	int a[5010],z=1,t=0;
	for(int i=0;i<5001;i++){
		if(s[i]<=9 &&s[i]>=0){
			a[z]=s[i];
			z++;	
		}
		if(s[i]=='0') break;
	}
	int p=0;
	for(int i=0;i<z;i++){
		for(int j=0;j<z;j++){
			if(a[j]>t){
				t=a[j];
				p=j;
			} 
		}
		std::cout<<t;
		a[p]=-1;
		t=0;
	}
}       




