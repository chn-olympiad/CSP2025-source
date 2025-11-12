#include<iostream>
using namespace std;
int main(){
	string s;
	for(int i=0; i<=9; i++){
		getline(cin,s);
		string x;
		cin>>x;
		if(s>x){
			s=x;
 		}
	}
 	cout<<s;
	return 0;
}
