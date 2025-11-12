#include<iostream>
#include<cstring>
using namespace std;
int main(){
	fropen("number.in","r",strin);
    fropen("number.out","w",strout);
	string a,b;
	char n;
	int c=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=a[i];
			c++;
		}
	}
	for(int i=0;i<c;i++){
        for(int j=0;j<c-i;j++){
			if(b[j]<=b[j+1]){
				n=b[j];
				b[j]=b[j+1];
				b[j+1]=n;
			}
		}
		
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}	
    return 0;
} 
