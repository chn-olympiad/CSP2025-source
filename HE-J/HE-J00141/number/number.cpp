#include <bits/stdc++.h>
using namespace std;
int main(void){
	char s[10000];
	cin>>s;
	int b=sizeof(s)/sizeof(s[0]),a[b],c;
	for(int i=0;i<b;i++){
		for(int j=0;j<10;j++){
			if(s[i]=j){	
				a[c]==s[j];
				c++;
			}
		}
	}
	int num;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		for(int j=0;j<<sizeof(a)/sizeof(a[0]);j++){
			if(a[j]<a[j+1]){
				num=a[j];
				a[j]=a[j+1];
				a[j+1]=num;
			}	
		}
	}
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}

