#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=9;i>=0;i--){
		for(int j=0;j<a.size();j++){
			if(a[j]-'0'==i){
				cout<<a[j];
			}
		}
	}
	return 0;
} 
