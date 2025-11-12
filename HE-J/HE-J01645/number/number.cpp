#include<iostream>
#include<string>
using namespace std;
int main(){
	//freopen("number.in","r","stdin");
	//freopen("number.out","w","stdout");
	string s;
	cin>>s;
	int x=s.size();
	int a[x];
	for(int i=0;i<x;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
		}else{
			a[i]=-1;
		}
	}
	int m=0;
	for(int j=0;j<x;j++){
		for(int i=0;i<x-1;i++){
			if(a[i]<a[i+1]){
				m=a[i];
				a[i]=a[i+1];
				a[i+1]=m;
			}
		}
	}
	for(int i=0;i<x;i++){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}
