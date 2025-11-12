#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int out=0;
	int iin=0;
	for(int i=0;i<a;i++){
		int b;
		cin>>b;
		for(int k=0;k<b;k++){
			for(int v=0;v<3;v++){
				int in;
				cin>>in;
				if(in>=iin){
					iin=in;
				}
			}
			out+=iin;
		}
		cout<<out;
	}
	return 0;
} 
