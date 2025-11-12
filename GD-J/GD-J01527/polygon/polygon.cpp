#include <bits/stdc++.h>
using namespace std;
int cmd(int a,int b){
	return a>b; 
}
int main()
{
	int a,ma=0; 
	cin>>a;
	int b[a]={};
	for(int i=0;i<a;i++){
		cin>>b[i];

	}
	sort(b,b+a,cmd);
	for(int i=3;i<=a;i++){
		
	}		
	return 0;
}
