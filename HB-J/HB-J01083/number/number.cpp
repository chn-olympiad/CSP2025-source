#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int s;
	cin>>s;
	int ar[]={0};
	for(int i=0;;i++){
		ar[i]=s%10;
		s=s/10;
		if(s==0){
			break;
		}
	}
	for(int i=0;;i++){
		for(int j=1;;j++){
			if(ar[j]>ar[j-1]){
				int b=0;
				b=ar[j];
				ar[j]=ar[j-1];
				ar[j-1]=b;
			}
			s=s/10;
		    if(s==0){
		     	break;
	    	}
	    }
	}
	int num=0;
	for(int i=0;;i++){
		num=num*10+ar[i];
		s=s/10;
		if(s==0){
			break;
		}
	}
	cout<<num;
	return 0;
}
