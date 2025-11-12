#include<iostream>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstring>
using namespace std;
char a[1000001];
char b[1000001];
int find(char c[1000001]){
	int x=0;
	int len2=strlen(c);
	for(int i=0;i<len2;i++){
		if(c[i]>x){
			x=c[i];
		} 
	}
	return x;
}
int find2(char c[1000001]){
	int y=0;
	int x=0;
	int len2=strlen(c);
	for(int i=0;i<len2;i++){
		if(c[i]>x){
			x=c[i];
			y=i;
		} 
	}
	return y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int maxn=0;
	cin>>a;
	int len=strlen(a);
	if(len==1){
		cout<<a;
		return 0;
	}
	for(int i=0;i<len;i++){
	    if(a[i]>='0'&&a[i]<='9'){
	    	b[i]=a[i];
		}
	}
	int len2=strlen(b);
	for(int i=0;i<len2;i++){
		cout<<find(b);
		a[find2(b)]=0;
	}
	return 0;
} 
