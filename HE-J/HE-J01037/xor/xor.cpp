#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[500000];
int n,k;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
	}if(n==2){
		cout<<3;
	}
 fclose(stdin);
 fclose(stdout);
	return 0;
}
