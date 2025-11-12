#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int c[1000000]={0},j=0,x=a.size();
	for(int i=0;i<x;i++){
		if(a[i]<='9' && a[i]>='0'){
			c[j]=a[i]-'0';
			j++;
		}
	}
	sort(c,c+j);
	for(int i=j-1;i>=0;i--){
		printf("%d",c[i]);
	}
	return 0;
}
