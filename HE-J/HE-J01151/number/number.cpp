#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	long long num[str.length()]={0};
	long long used=0;
	for(int i=0;i<str.length();i++){
		char now=str[i];
		int n=now;
		if(n<48 || n>57) continue;
		else{
			num[used]=n-48; 
			used++;
		} 
	}
	
	long long px[used];
	long long max=0;
	long long pxused=0;
	for(int i=0;i<used;i++){
		for(int j=0;j<used;j++){
			if(num[j]>num[max]) max=j;
		}
		px[pxused]=num[max];
		num[max]=-1;
		pxused++;
	}
	for(int i=0;i<pxused;i++) cout<<px[i];
	return 0;
}
