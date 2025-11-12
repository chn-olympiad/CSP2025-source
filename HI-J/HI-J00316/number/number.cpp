#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int x,n=0;
	char s[1000010],a[1000010];
	cin>>s;
	x=strlen(s);
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
			for(int j=n-1;j>0;j--){
				if(a[j]>a[j-1]){
					char m=a[j];
					a[j]=a[j-1];
					a[j-1]=m;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
