#include <bits/stdc++.h>

using namespace std;

char a[1000];
int b[1000];
int c=0,pai;
int main(){
	
	cin>>a;
	
	for(int i=0;i<1000;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=a[i]-48;
			c++;
		}
		
	}
	for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
        	if(b[i]>b[j]){
			pai=b[i];
			b[i]=b[j];
			b[j]=pai;
			}
		}
    }
    for(int i=0;i<c;i++){
    	cout<<b[i];
	}
    return 0;
}

