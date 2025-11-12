#include<bits/stdc++.h>
using namespace std;
int n,m,x,c;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a,a+x,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==c){
			c=i;
		}
	}
	if(c%2==1){
		cout<<(c+1)/2;
	}else{
		cout<<c/2;
	}
	cout<<" ";
	
	return 0;
}