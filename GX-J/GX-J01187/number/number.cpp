#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10],b[10];
	int n=0;
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	for(int i=1;i<=10;i++){
		if(a[i]>='1'&&a[i]<='9'){
			b[i]=a[i];
		}
	}
	for(int i=1;i<=10;i++){
		if(n<b[i]){
			n=b[i];
			cout<<n;
			b[i]=0;
		}
	}
	return 0;
}
