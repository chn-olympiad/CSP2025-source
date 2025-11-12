#include<bits/stdc++.h> 
using namespace std;
int b[1000000];
int p(int x,y){
	int max,t,n;
	for(int i=x;i<=y;i++){
		t=t+i;
		if(i>=max) max=i;}
	if(n>=3&&t>(max*2)) return true;
	else return false;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=n;i<n;i++){
		cin>>a[i];
}
	return 0;
}
