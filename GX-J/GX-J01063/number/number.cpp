#include<bits/stdc++.h>
using namespace std;
long long arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s,sz,szc,i=1;
	cin>>s;
	while(s==0){
		sz=s%10;
		s=s/10;
		if(sz==0||sz==1||sz==2||sz==3||sz==4||sz==5||sz==6||sz==7||sz==8||sz==9){
			arr[i]=sz;
			i++;
		}		
	}	
	for(int n=1;n<=i;i++){
		if(arr[n+1]>arr[n]){
			arr[n]=arr[n+1];
		}	
	}	
	for(int n=1;n<=i;n++){
		for(int y=1;y<=i;y++){	
			arr[n]*=10;
		}	
		szc=szc+arr[n];
	}	
	cout<<szc;
	return 0;
}
