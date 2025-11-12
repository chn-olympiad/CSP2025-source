#include<bits/stdc++.h>
using namespace std;
int n,c[5005];
int main(){
	scanf("%d",&n);
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b<c||a+c<b||b+c<a){
			cout<<0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	
	return 0;
}

















































































































































































//只是一些马 : 马 騳 驫 
