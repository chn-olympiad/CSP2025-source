#include<iostream>
#include <bits/requires_hosted.h>
#include<algorithm>
#include<stdio.h>
#include<ostream>
#include<string>
using namespace std;
int t[1000001];
int number(string a){
	int l=a.size();
	
	int temp=0;
	for(int i=0;i<l;i++){
		if('0'<=a[i]&&a[i]<='9'){
			int t2=a[i]-'0';
			t[temp]=t2;
			temp++;
		}
	}
	return temp;
}
bool uuuu(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int b=number(a);
	sort(t,t+b,uuuu);
	for(int i=0;i<b;i++){
		cout<<t[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
