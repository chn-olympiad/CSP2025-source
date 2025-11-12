#include<bits/stdc++.h>
using namespace std;

long long int a,b,s[100];

 
int main(){
	int sum=1;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		for(int c=1;c<=b;c++){
			cin>>s[sum];
			sum++;
		}
	}
	int wei=a*b,r=s[1],c=1,h,l;
	for(int i=1;i<=wei;i++){
		if (r<s[i]){
			c++;
		}}
		if (c%a!=0){
			l=c/a+1;
		}
		else{l=c/a;
		}
		if(l%2==0){
			h=(a+1)-c/l;
		}
		else{
		if (l!=1){
			h=c%l;}
		else{
			h=c;
		}	
		}
		cout<<l<<" "<<h;
		return 0;
} 
