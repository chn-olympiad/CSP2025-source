#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(;;){
		int s;
		cin>>s;
		if(s=1){
			int m;
			cin>>m;
			if(m<n){
				cout<<m;
			}else{
				cout<<n;
			}
		}else{
			cout<<0;
		}
    }
	return 0;
} 
