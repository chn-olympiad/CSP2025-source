#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	int n;
 	cin>>n;
 	if(n%6!=0){
 		cout<<n%6;
	}else{
	 	cout<<n%5;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
 }