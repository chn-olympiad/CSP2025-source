#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int a[100000];
	cin>>s;
	for(int i=1;i<=size.of(s);i++){
	if(s[i]>='1'&&s[i]<='9'){
		a[i]+=s[i];
		}
	}
	for(int i=1;i<=size.of(s);i++){
	if(a[i]<a[i+1]){
		int a;
		a=a[i];
		a[i]=a[i+1];
		a[i+1]=a[i];
	}
	}
	for(int i=1;i<=size.of(s);i++){
	cout<<a[i];
	}
	return 0;
}
