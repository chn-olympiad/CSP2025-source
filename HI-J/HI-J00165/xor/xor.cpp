#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,max=0,i;
	for(int i=0;i<n*k;i++){
		cin>>a[i];
	}
	if(a[i]>n&&a[i]<k&&a[i]>max){
		cout<<a[i];
	}
	else if(k==0){
		cout<<"1";
	}
	else{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
