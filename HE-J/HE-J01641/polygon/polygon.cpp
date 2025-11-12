#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m[1001];
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	if(n<3){
		cout<<"0";
	}
	if(n=3){
		if(max(m[0],max(m[1],m[2]))<m[0]+m[1]+m[2]-max(m[0],max(m[1],m[2]))){
			cout<<"1"; 
		}else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
