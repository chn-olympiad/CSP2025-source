#include<iostream>
#include <bits/requires_hosted.h>
#include<algorithm>
#include<stdio.h>
#include<ostream>
#include<string>
using namespace std;
int seat[20][20];
int number[120];
void slove(int n,int m){
	int t=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				
				seat[i][j]=number[t];
				t++;
			
			
			}
		}else{
			for(int j=n;j>=1;j--){
				seat[i][j]=number[t];
				t++;
			}
		}
		}
	}

bool uuuu(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>number[i];
	}
	int k=number[1];
	int a,b;
	sort(number+1,number+n*m+1,uuuu);
	slove(n,m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k==seat[i][j]){
				a=i;
				b=j;
				break;
			}
		}
	}
	cout<<a<<" "<<b;
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	 
	return 0;
}
