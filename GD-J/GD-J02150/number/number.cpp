#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.length(),c[20],n=0;
	for(int i=9;i>=0;i--){
		c[i*2] = i;
		c[i*2+1]=0;
	}
	for(int i=0;i<b;i++){
		if(a[i] >='0' && a[i]<='9'){
			n = int(a[i])-48;
			n=n*2+1;
			c[n]++;
		}
	}
	n=0;
	for(int i=9;i>=0;i--){
		if(c[i*2+1]!=0){
			for(int j=0;j<c[i*2+1];j++){
				n = n*10+c[i*2];
			}
		}
	}
	cout<<n;
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
