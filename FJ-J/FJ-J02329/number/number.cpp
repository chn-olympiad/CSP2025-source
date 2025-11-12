#include<bits/stdc++.h>
using namespace std;

int main(){
	char a[100];
	int b[100];
	int m,k=0;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(int(a[i])>=48 && int(a[i])<=57){
			b[k]=int(a[i]);
			k++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(b[j]<b[j+1]){
				int temp;
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp; 
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<char(b[i]);
	}
return 0;
}
