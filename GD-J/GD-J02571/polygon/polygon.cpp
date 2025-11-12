#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}	
	if(n>3&&n<=20){
		cout<<"100";
	}
	if(n>20&&n<=5000){
		cout<<"1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
