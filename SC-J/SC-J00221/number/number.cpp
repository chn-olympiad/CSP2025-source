#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int ab[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char a;
    while(cin>>a){
//    	if(a=='S')
//    	break;
    	if(int(a)<int('a')) 
    	ab[int(a)-int('0')]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ab[i];j++){
		printf("%d",i);
		}
	}
	return 0;
}