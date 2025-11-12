#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int zxz(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	} 
	}
	char zxp=a[0];
	sort(a,a+1,zxz);
	for(int i=0;i<n*m;i++){
	   if(n==1&&m>1){
	   		if(zxp==a[i]){
	   			cout<<i+1;
	   			return 0;
			   }
	   }
	   if(n>1&&m==1){
	   		if(zxp==a[i]){
	   			cout<<i+1;
	   			return 0;
			   }
	   }
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

