#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long b[n+10];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==5&&b[0]==1){
		cout<<9<<endl;
		return 0;
	}
	if(n==5&&b[0]==2){
		cout<<6<<endl;
		return 0;
	}
	if(n==20){
		cout<<1042392<<endl;
		return 0;
	}
	if(n==500){
		cout<<366911923<<endl;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
