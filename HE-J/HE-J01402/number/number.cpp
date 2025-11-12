#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int tmp(int a,int b){
	return a>b;
}
int main(){
	string a;
	cin>>a;
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	if(a.length()==1){
		cout<<a[a.length()-1];
		return 0;
	}
	int a2[1000],o=0;
	for(int i=0;i<a.length() ;i++){
		if(a[i]>='0'&&a[i]<='9'){
			a2[o]=int(a[i]);
			o++;
		}
	}
	cout<<o<<endl;
	sort(a2,a2+o,tmp);
	for(int i=0;i<o;i++){
		cout<<char(a2[i])<<endl;
	}
	return 0;
}
