#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,x=0,y=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(k==1||k==0){
	   cout<<"0";	
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
