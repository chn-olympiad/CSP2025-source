#include<bits/stdc++.h>
using namespace std;
long long n;
bool dx(char a,char b){
	char c;
	if(a>=b){
		c=a;
		a=b;
		b=c;
	}
	return b;
}
int main(){
	cin>>n;
	char a[n+7];
	char z[n+7];
	for(int i=1;i<=n;i++){
		z[i]=0;
		cin>>a[i];
		if(a[i]>='0'&&a[i]<='9'){
			z[i]=a[i];
		}		
	}
	for(int j=1;j<=n+1;j++){
		dx(z[j-1],z[j]);
		cout<<z[j];
	}
    return 0;
}