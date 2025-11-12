#include<bits/stdc++.h>
using namespace std;
int main(){
	//frepen("number.in","r",stdin);
	//frepen("number.out","w",stdout);
	char n[10000];
	long long c[10000],d=1,a,b[10000],g=1;
	for(int i=1;i<=1;i++){
		d++;
		cin>>n[i];
		if(!(n[i]>'a'&&n[i]<'z')){
			c[d]=n[i];
		}
	}
	for(int i=d;i>=1;i--){
		for(int j=1;j<=i-1;j++){
			if(c[i]>c[i-1]){
				a=c[i];
				c[i]=c[i-1];
				c[j-1]=a;
			}
		}
		b[g]=c[i];
		g++;
	}
	for(int i=1;i<=d;i++){
		cout<<b[i];
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
	
